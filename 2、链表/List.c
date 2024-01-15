#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;

	tail->next = newNode;
	newNode->prev = tail;
	phead->prev = newNode;
	newNode->next = phead;
	
}
