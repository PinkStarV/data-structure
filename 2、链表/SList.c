#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


SL* SLNode(SLTDateType x)
{
	SL* NewNode = (SL*)malloc(sizeof(SL));
	NewNode->data = x;
	NewNode->next = NULL;
	if (NewNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
}
void SLPrint(SL* p)
{
	SL* cur = p;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}
void SLPushBack(SL** p, SLTDateType x)
{
	SL* NewNode = SLNode(x);
	if (*p == NULL)
	{
		*p = NewNode;
	}
	else
	{
		SL* cur = *p;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}

		cur->next = NewNode;

	}

}
void SLFront(SL** p, SLTDateType x)
{
	SL* newnode = SLNode(x);
	newnode->next = *p;
	*p = newnode;

}
void SListPopBack(SL** p)
{
	assert(*p != NULL);
	if ((*p)->next == NULL)
	{
		free(*p);
		*p = NULL;
	}
	else
	{
		//урн╡
		SL* cur = *p;
		SL* Last = NULL;
		while (cur->next != NULL)
		{
			Last = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		Last->next = NULL;
	}
}
void SListPopFront(SL** p)
{
	assert(*p != NULL);
	SL* next = (*p)->next;
	free(*p);
	*p = next;

}
SL* SListFind(SL* p, SLTDateType x)
{
	SL* cur = p;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsert(SL** phead, SL* pos, SLTDateType x)
{
	SL* cur = SLNode(x);
	if (*phead == pos)
	{
		cur->next = *phead;
		*phead = cur;
	}
	else
	{
		SL* posPrev = *phead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = cur;
		cur->next = pos;
	}
}
void SListErase(SL** p, SL* pos)
{
	if (*p = pos)
	{
		*p = pos->next;
		free(pos);
	}
	else
	{
		SL* prev = *p;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
void SListInsertAfter(SL* pos, SLTDateType x)
{
	SL* newNode = SLNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListDestory(SL** p)
{
	assert(p);
	SL* cur = *p;
	while (cur)
	{
		SL* next = cur->next;
		free(cur);
		cur = next;
	}
 
}