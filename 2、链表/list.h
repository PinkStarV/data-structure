#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();
void ListPushBack(LTNode* phead, LTDateType x);
