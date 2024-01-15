#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
#define MAX_NODE 10
#define KEY(n) (n ? n->key : -1) //宏定义
typedef struct Node {
	int key;
	struct Node* lchild, * rchild;
}Node;
//创建新节点
Node* getNewNode(int key) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;

}
//插入
Node* insert(Node* root, int key) {
	if (root == NULL) return getNewNode(key);
	if (rand() % 2) root->lchild = insert(root->lchild, key);
	else root->rchild = insert(root->rchild, key);
	return root;
}
//创建随机二叉树
Node* getRandomBinaryTree(int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++){
		root = insert(root, rand() & 100);
	}
	return root;
}
//销毁二叉树
void clear(Node* root) {
	if (root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return;
}
char buff[1000];
int len = 0;
//二叉树转广义表的封装函数
void __serialize(Node* root) {
	if (root == NULL) return;
	//root
	len += snprintf(buff + len,100,"%d",root->key);
	if (root->lchild == NULL && root->rchild == NULL) return;
	len += snprintf(buff + len,100, "(");
    __serialize(root->lchild);
	if (root->rchild != NULL) {
		len += snprintf(buff + len, 100, ",");
		__serialize(root->rchild);
	}
	
	len += snprintf(buff + len,100, ")");
	return;
}
//二叉树转广义表
void serialize(Node* root){
	memset(buff, 0, sizeof(buff));
	len = 0;
	__serialize(root);
	return;
}
Node* deserialize(char* buff,int len) {
	Node** s = (Node**)malloc(sizeof(Node*) * MAX_NODE);
	int top = -1,flag = 0,scode = 0;
	Node* p = NULL,*root = NULL;
	for (int i = 0; buff[i]; i++) {
		switch (scode) {
		case 0: {
			if (buff[i] >= '0' && buff[i] <= '9') scode = 1;
			else if (buff[i] == '(') scode = 2;
			else if (buff[i] == ',') scode = 3;
			else scode = 4;
			i -= 1;
		}break;
		case 1: {
			int key = 0;
			while (buff[i] <= '9' && buff[i] >= '0') {
				key = key * 10 + (buff[i] - '0');
				i += 1;
			}
			p = getNewNode(key);
			if (top >= 0 && flag == 0) s[top]->lchild = p;
			if (top >= 0 && flag == 1) s[top]->rchild = p;
			i--;
			scode = 0;
		}break;
		case 2: {
			s[++top] = p;
			flag = 0;
			scode = 0;
		}break;
		case 3: {flag = 1; scode = 0; }break;
		case 4: {
			root = s[top--];
			scode = 0;
		}break;
		}
		
	}
	return root;
}
//打印二叉树节点的函数
void print(Node* root) {
	printf("%d(%d,%d)\n", 
		KEY(root),
		KEY(root->lchild),
		KEY(root->rchild)
	);
 }
//输出一个二叉树的先序遍历
void output(Node* root) {
	if (root == NULL) return;
	print(root);
	output(root->lchild);
	output(root->rchild);
	return;
}
int main(){
	srand(time(0));
	Node* root = getRandomBinaryTree(MAX_NODE);
	serialize(root);
	output(root);
	printf("Buff[] :%s\n", buff);

	//反序列化 广义表转二叉树
    Node* new_root = deserialize(buff, len);
	output(new_root);
	return 0;
}