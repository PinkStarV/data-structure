#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROOT 1
#define FATHER(i) ((i) / 2)
#define cmp > 
#define LEFT(i) ((i) * 2)
#define RIGHR(i) ((i) * 2 + 1)
#define SWAP(a,b,type){type tmp = a;\
                            a = b;\
							b = tmp;}


typedef struct PriorityQueue {
	int* __data , *data;
	int size;    //最多能存储多少元素
    int n;       //存储了多少元素
}PriorityQueue;

PriorityQueue* initPQ(int size) {
	PriorityQueue* p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	p->__data = (int*)malloc(sizeof(int) * size);
	p->data = p->__data - 1;
	p->size = size;
	p->n = 0;
	return p;
}

int empty(PriorityQueue* p) {
	return  p->n == 0;
}

int full(PriorityQueue* p) {
	return p->n == p->size;
}

int top(PriorityQueue* p) {
	return p->data[ROOT];
}

void up_maintain(int* data, int i) {
	if (i == ROOT) return;
	while(i >ROOT &&(data[i] cmp data[FATHER(i)]) ){
	    SWAP(data[i], data[FATHER(i)], int);
		i = FATHER(i);
	}
	return;

}

int Push(PriorityQueue* p, int x) {
	if (full(p)) return 0;
	p->n += 1;
	p->data[p->n] = x;
	up_maintain(p->data, p->n);
	return 1;
}
void down_updata(int* data, int i,int n) {
	int ind;    //指向三元组中的最大值
	while (LEFT(i) <= n) {
		ind = i;
		int l = LEFT(i), r = RIGHR(i);
		if (data[l] cmp data[ind]) ind = l;
		if (r <= n && data[r] cmp data[ind]) ind = r;
		if (ind == i) break;
		SWAP(data[i], data[ind],int);
		i = ind;
	}
	return;
}
int pop(PriorityQueue* p) {
	if (empty(p)) return 0;
	p->data[ROOT] = p->data[p->n];
	p-> n -= 1;
	down_updata(p->data, ROOT,p->n);
	return 1;
}

void clear(PriorityQueue* p) {
	if (p == NULL) return;
	free(p->__data);
	free(p);
	return;
}

void output(PriorityQueue* p) {
	printf("PQ(%d) : ", p->n);
	for (int i = 1; i <= p->n; i++) {
		printf("%d ", p->data[i]);

	}
	printf("\n");
	return;
}

int main() {
#define MAX_OP 100
	int op,x;
	PriorityQueue* p = initPQ(MAX_OP);
	while (~scanf("%d", &op)) {		//	op == 1 在堆（优先队列）中插入元素
		if (op == 1) {
			scanf("%d", &x);
			printf("inster %d to priority_queue :\n", x);
			Push(p, x);
			output(p);
		}
		else {						// op ！= 1 弹出头部元素。
			printf("pop : %d\n", top(p));
			pop(p);
			output(p);
		}
	}

	return 0;
}