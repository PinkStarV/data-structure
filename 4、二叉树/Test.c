#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

void TestTree1()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->left = NULL;
	A->right = NULL;
	A->data = 'A';

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->left = NULL;
	B->right = NULL; 
	B->data = 'B';

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->left = NULL;
	C->right = NULL;
	C->data = 'C';

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
    D->left = NULL;
	D->right = NULL;
	D->data = 'D';

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->left = NULL;
	E->right = NULL;
	E->data = 'E';

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
}

void TreeTest3()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->left = NULL;
	A->right = NULL;
	A->data = '1';

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->left = NULL;
	B->right = NULL;
	B->data = '4';

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->left = NULL;
	C->right = NULL;
	C->data = '3';

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->left = NULL;
	D->right = NULL;
	D->data = '2';

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->left = NULL;
	E->right = NULL;
	E->data = '5';

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	 
}
void TestTree2()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->left = NULL;
	A->right = NULL;
	A->data = 'A';

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->left = NULL;
	B->right = NULL;
	B->data = 'B';

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->left = NULL;
	C->right = NULL;
	C->data = 'C';

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->left = NULL;
	D->right = NULL;
	D->data = 'D';

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->left = NULL;
	E->right = NULL;
	E->data = 'E';

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;


	//	int Asize = 0;
	//	TreeSize(A, &Asize);
	//	printf("%d", Asize);
	//
	//	int Bsize = 0;
	//	TreeSize(B, &Bsize);
	//	printf("%d", Bsize);
	
	printf("TreeSize : %d\n", TreeSize(A));
	printf("TreeSize : %d\n", TreeSize(B));

	LevelOrder(A);
}

int main()
{
	TestTree2();
	return 0;
}







