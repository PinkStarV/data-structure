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
Node* getNewNode(char ch, int freq) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->freq = freq;
	p->ch = ch;
	p->lchild = p->rchild = NULL;
	return p;
}
void swap_node(Node** node_arr, int i, int j) {
	Node* temp = node_arr[i];
	node_arr[i] = node_arr[j];
	node_arr[j] = temp;
	return;
}
int find_min_node(Node** node_arr,int n) {
	int ind = 0;
	for (int j = 1; j <= n; j++) {
		if (node_arr[ind]->freq > node_arr[j]->freq) ind = j;
	}
	return ind;
}
Node* buildHaffmanTree(Node** node_arr, int n) {
	for (int i = 1; i < n; i++) {
		// find two node
		int ind1 = find_min_node(node_arr, n - i);
		swap_node(node_arr, ind1, n - i);
		int ind2 = find_min_node(node_arr, n - i - 1);
		swap_node(node_arr, ind2, n - i - 1);
		// merge two node
		int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
		Node* node = getNewNode(0, freq);
		node->lchild = node_arr[n - i - 1];
		node->rchild = node_arr[n - i];
		node_arr[n - i - 1] = node;
	}
	return node_arr[0];
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
	int n,freq;
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