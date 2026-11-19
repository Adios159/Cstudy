#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define true 1
#define false 0

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

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
    GraphNode* node2;
    if(u >= g->n || v >= g->n || u < 0 || v < 0) {
        fprintf(stderr, "No EXIST VERTEX!\n");
        return;
    }
    node1 = (GraphNode*)malloc(sizeof(GraphNode));
    if(u != v) {
        node2 = (GraphNode*)malloc(sizeof(GraphNode));
    }

    node1->vertex = v;
    node1->link = g->list[u];
    g->list[u] = node1;

    node2->vertex = u;
    node2->link = g->list[v];
    g->list[v] = node2;
}

void dfs(GraphType *g, int v) {
    GraphNode* w;
    visited[v] = true;
    printf("edge #%d -> ", v);
    for(w = g->list[v]; w; w = w->link) {
        if(!visited[w->vertex]) {
            dfs(g, w->vertex);
        }
    }
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
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    print_list(g);

    dfs(g, 0);
    printf("\n");

    free(g);
    return 0;
}