#define _CRT_SECURE_NO_WARNINGS 1
//#include "SList.h"
//void TestList1()
//{
//	SL* plist = NULL;
//	SLPushBack(&plist, 1);
//	SLPushBack(&plist, 2);
//	SLPushBack(&plist, 3);
//	SLPushBack(&plist, 4);
//
//	SLPrint(plist);
//
//	SLFront(&plist, 1);
//	SLFront(&plist, 2);
//	SLFront(&plist, 3);
//	SLFront(&plist, 4);
//
//	SLPrint(plist);
//
//}
//void TestList2()
//{
//	SL* plist = NULL;
//	SLFront(&plist, 1);
//	SLFront(&plist, 2);
//	SLFront(&plist, 3);
//	SLFront(&plist, 4);
//
//	SListPopBack(&plist);
//
//	SLPrint(plist);
//
//}
//void TestList3()
//{
//	SL* plist = NULL;
//	SLFront(&plist, 1);
//	SLFront(&plist, 2);
//	SLFront(&plist, 3);
//	SLFront(&plist, 4);
//
//	SLPrint(plist);
//
//	SListPopFront(&plist);
//	SLPrint(plist);
//
//	SListPopFront(&plist);
//	SLPrint(plist);
//
//	SListPopFront(&plist);
//	SLPrint(plist);
//
//	SListPopFront(&plist);
//	SLPrint(plist);
//}
//void TestList4()
//{
//	SL* plist = NULL;
//	SLFront(&plist, 1);
//	SLFront(&plist, 2);
//	SLFront(&plist, 3);
//	SLFront(&plist, 2);
//	SLFront(&plist, 4);
//	SLFront(&plist, 2);
//	SLPrint(plist);
//
//	SL* pos = SListFind(plist, 2);
//	int i = 1;
//	while (pos)
//	{
//		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
//		pos = SListFind(pos->next, 2);
//	}
//	//修改 3->30
//	pos = SListFind(plist, 3);
//	if (pos)
//	{
//		pos->data = 30;
//	}
//	SLPrint(plist);
//}
//void TestList5()
//{
//	SL* plist = NULL;
//	SLFront(&plist, 1);
//	SLFront(&plist, 2);
//	SLFront(&plist, 3);
//	SLFront(&plist, 2);
//	SLFront(&plist, 4);
//	SLFront(&plist, 2);
//	SLPrint(plist);
//	
//
//	SL* pos = SListFind(plist, 3);
//	if (pos)
//	{
//		SListInsert(&plist, pos, 30);
//	}
//	SLPrint(plist);
//	SListDestory(&plist);
////}
////int main()
//{
//	//TestList1();
//	//TestList2();
//	//TestList3();
//	//TestList4();
//	TestList5();
//
//	return 0;
//}
#include "List.h"

void TestList1()
{   
	LTNode* plist=ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
}

int main()
{
	TestList1();
	return 0;
}