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

void insert_vertex(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "VERTEX OVERFLOW!");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v) {
    GraphNode* node1;
    if(u >= g->n || v >= g->n || u < 0 || v < 0) {
        fprintf(stderr, "No EXIST VERTEX!\n");
        return;
    }
    node1 = (GraphNode*)malloc(sizeof(GraphNode));

    node1->vertex = v;
    node1->link = g->list[u];
    g->list[u] = node1;
}

void print_list(GraphType *g) {
    for(int i = 0; i < g->n; i++) {
        GraphNode* p = g->list[i];
        printf("list of edge #%d", i);
        while(p != NULL) {
            printf(" -> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    int n, i, j, x, ones = 0;
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < n; i++) {
        insert_vertex(g, i);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fp, "%d", &x);
            if (x == 1) {
                insert_edge(g, i, j);
                ones++;
            }
        }
    }

    print_list(g);
    free(g);
    fclose(fp);
    return 0;
}