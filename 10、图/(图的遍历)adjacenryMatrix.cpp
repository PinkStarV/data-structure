#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
using namespace std;
typedef struct Graph {
	char* vexs;     //点
	int** arcs;    //边
	int vexNum, arcNum;
};

Graph* initGraph(int VexNum) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * VexNum);
	G->arcs = (int**)malloc(sizeof(int*) * VexNum);
	for (int i = 0; i < VexNum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * VexNum);
	}
	G->vexNum = VexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph* G, char* vexs, int* arcs) {
	for (int i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if (G->arcs[i][j] != 0) G->arcNum++;
		}
	}
	G->arcNum /= 2;
	return;
}
//深度优先遍历
void DFS(Graph* G, int* visited, int index) {
	printf("%c\t", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] == 1 && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}
//广度优先遍历
void BFS(Graph* G, int* visited,int index) {
	queue<int> q;
	printf("%c\t", G->vexs[index]);
	visited[index] = 1;
	q.push(index);
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[i][j] == 1 && !visited[j]) {
				printf("%c\t", G->vexs[j]);
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}

int main() {
	Graph* G = initGraph(5);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) {
		visited[i] = 0;
	}
	int arcs[5][5] = {
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};
	char ch[] = "ABCDE";
	createGraph(G, ch, (int*)arcs);
	DFS(G, visited, 0);
	for (int i = 0; i < G->vexNum; i++) {
		visited[i] = 0;
	}
	printf("\n");
	BFS(G, visited, 0);
	return 0;
}
