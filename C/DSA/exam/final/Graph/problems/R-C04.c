#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 100

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* list[MAX_VERTICES];
} GraphType;

void init(GraphType *g) {
    int v = 0;
    g->n = 0;
    for(v = 0; v < MAX_VERTICES; v++) {
        g->list[v] = NULL;
    }
}

int start[MAX_VERTICES] = {0};
int end[MAX_VERTICES] = {0};

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    int n, i, s, e, d;
    fscanf(fp, "%d", &n);
   

    while(fscanf(fp, "%d %d", &s, &e) == 2) {
        ++start[s];
        ++end[e];
    }

    printf("%4s %5s %5s\n", "vertex", "start", "end");
    for(int i = 0; i < n; i++) {
        printf("%4d %5d %5d\n", i, end[i], start[i]);
    }
    fclose(fp);
    return 0;
}