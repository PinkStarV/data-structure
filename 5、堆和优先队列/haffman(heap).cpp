#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

typedef struct Node {
	struct Node* lchild, * rchild;
	int freq;                             //字符出现的频次
	char ch;
}Node;

void swap(Node* a, Node* b) {
	Node* c = (Node*)malloc(sizeof(Node));
	c->ch = a->ch;
	c->freq = a->freq;
	a->ch = b->ch;
	a->freq = b->freq;
	a->ch = c->ch;
	a->freq = c->freq;
	return;
}

typedef struct Heap {
	Node** __data, ** data;
	int n, size;   //size是总大小

}Heap;

Heap* getNewHeap(int size) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->__data = (Node**)malloc(sizeof(Node*) * size);
	h->data = h->__data - 1;
	h->n = 0;
	h->size = size;
	return h;
}

bool fullHeap(Heap* h) {
	return h->n == h->size;
}

bool emptyHeap(Heap* h) {
	return h->n == 0;
}

Node* top(Heap* h) {
	if (emptyHeap(h)) return NULL;
	return h->data[1];
}

void up_update(Heap* h, int i) {
	while (i > 1 && h->data[i]->freq < h->data[i / 2]->freq) {
		swap(h->data[i], h->data[i / 2]);
		i /= 2;
	}
	return;
}

void down_update(Heap* h, int i) {
	while (i * 2 <= h->n) {
		int ind = i, l = i * 2, r = i * 2 + 1;
		if (h->data[l]->freq < h->data[ind]->freq) ind = l;
		if (r <= h->n && h->data[r]->freq < h->data[ind]->freq) ind = r;
		if (ind = i) return;
		swap(h->data[i], h->data[ind]);
		i = ind;
	}
	return;
}

int Heap_Pop(Heap* h) {
	if (emptyHeap(h)) return 0;
	h->data[1] = h->data[h->n];
	h->n -= 1;
	down_update(h, 1);
	return 1;
}

int Heap_Push(Heap* h, Node* n) {
	if (fullHeap(h)) return 0;
	h->n++;
	h->data[h->n] = n;
	up_update(h, h->n);
	return 1;
}

void clearHeap(Heap* h) {
	if (h == NULL) return;
	free(h->__data);
	free(h);
	return;
}
//获取新节点
Node* getNewNode(char ch, int freq) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->freq = freq;
	p->ch = ch;
	p->lchild = p->rchild = NULL;
	return p;
}
//交换函数
void swap_node(Node** node_arr, int i, int j) {
	Node* temp = node_arr[i];
	node_arr[i] = node_arr[j];
	node_arr[j] = temp;
	return;
}

int find_min_node(Node** node_arr, int n) {
	int ind = 0;
	for (int j = 1; j <= n; j++) {
		if (node_arr[ind]->freq > node_arr[j]->freq) ind = j;
	}
	return ind;
}
Node* buildHaffmanTree(Node** node_arr, int n) {
	Heap* h = getNewHeap(n);
	for (int i = 0; i < n; i++) Heap_Push(h, node_arr[i]);
	for (int i = 1; i < n; i++) {
		// find two node
		Node* node1 = top(h);
		Heap_Pop(h);
		Node* node2 = top(h);
		Heap_Pop(h);
		Node* node3 = getNewNode(0, node1->freq + node2->freq);
		node3->lchild = node1;
		node3->rchild = node2;
		Heap_Push(h, node3);
	}
	Node* ret = top(h);
	clearHeap(h);
	return ret;
}

void clear(Node* root) {
	if (root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return;
}

#define MAX_CHAR_NUM 128
char* char_code[MAX_CHAR_NUM] = { 0 };
//哈夫曼编码
void extractHaffmanCode(Node* root, char buff[], int k) {
	buff[k] = 0;
	if (root->lchild == NULL && root->rchild == NULL) {
		char_code[root->ch] = _strdup(buff);
		return;
	}
	buff[k] = '0';
	extractHaffmanCode(root->lchild, buff, k + 1);
	buff[k] = '1';
	extractHaffmanCode(root->rchild, buff, k + 1);
	return;
}
void Test01() {
	srand(time(0));
	ofstream ofs;
	ofs.open("random.txt", ios::out);
	for (int i = 0; i < 26; i++) {
		ofs << (char)('a' + i) << endl
			<< rand() % 10000 << endl;
	}
	ofs.close();

}


void pre_order(Node* root)
{
	if (root == NULL) return;
	printf("%c ", root->ch);
	pre_order(root->lchild);
	pre_order(root->rchild);
	return;
}
int main() {
	//Test01();
	int n, freq;
	char c;
	n = 26;
	Node** node_arr = (Node**)malloc(sizeof(Node*) * n);
	ifstream ifs;
	ifs.open("random.txt", ios::in);
	for (int i = 0; i < n; i++) {
		ifs >> c;
		ifs >> freq;
		node_arr[i] = getNewNode(c, freq);
	}
	Node* root = buildHaffmanTree(node_arr, n);
	pre_order(root);
    char buff[1000];
	printf("\n");
	extractHaffmanCode(root, buff, 0);
	for (int i = 0; i < MAX_CHAR_NUM; i++) {
		if (char_code[i] == NULL) continue;
		printf("%c : %s\n", i, char_code[i]);
	}

	clear(root);

	return 0;
}
