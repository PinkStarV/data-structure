#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

#include "Queue.h"

void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
//void TreeSize(BTNode* root,int* size);
int TreeSize(BTNode* root);
int TreeLeafSize(BTNode* root);
void LevelOrder(BTNode* root);
void TreeDestory(BTNode* root);
