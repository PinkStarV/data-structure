#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SL;

void SLPrint(SL* p);
void SLPushBack(SL** p, SLTDateType x);
void SLFront(SL** p, SLTDateType x);
SL* SLNode(SLTDateType x);
void SListPopBack(SL** p);
void SListPopFront(SL** p);
SL* SListFind(SL* p, SLTDateType x);
//在pos位置后面插入，这个更合适，也更简单
void SListInsertAfter(SL* pos, SLTDateType x);
//在pos位置之前插入一个节点  pos节点通过find找到
void SListInsert(SL** phead,SL* pos,SLTDateType x);
void SListErase(SL** p, SL* pos);
void SListDestory(SL** p);