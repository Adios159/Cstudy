#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g) {
    int v;

    g->n = 0;
    for(v = 0; v < MAX_VERTICES; v++) {
        g->list[v] = NULL;
    }
}

void insert_vertex(GraphType *g, int v) {
    if((g->n) + 1 > MAX_VERTICES) {
        printf("VERTICES OVERFLOW!\n");
        exit(1);
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if(u >= g->n || v >= g->n) {
        printf("NO SUCH NODE!\n");
        exit(1);
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    if(node == NULL) {
        printf("ALLOCATE FAIL!\n");
        exit(1);
    }
    node->vertex = v;
    node->link = g->list[u];
    g->list[u] = node;
}

void topo_sort(GraphType *g) {
    
}

int main() {
    FILE *fp = fopen("data2.txt", "r");
    GraphType *g;
    char flag;
    int ver1, ver2;
    if(fp == NULL) {
        printf("NO FILE\n");
        exit(1);
    }

    while(!feof(fp)) {
        fscanf(fp, "%c", &flag);
        if(flag == 'v') {
            fscanf(fp, "%d", &ver1);
            insert_vertex(g, ver1);
        }
        else if(flag == 'e') {
            fscanf(fp, "%d %d", &ver1, &ver2);
            insert_edge(g, ver1, ver2);
        }
    }
    fclose(fp);

    topo_sort(g);
}