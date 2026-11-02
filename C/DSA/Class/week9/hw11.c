#define CRT_SECUER_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    GraphNode* adj_list[MAX_VERTICES];
    int n;
} GraphType;

int visited[MAX_VERTICES] = {0};

void init(GraphType* g) {
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if((g->n) + 1 > MAX_VERTICES) {
        printf("MAX VERTICES");
        return;
    }
    g->n++;

}

void insert_edge(GraphType* g, int s, int e) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if(((s < 0) || (s >= g->n)) || ((e < 0) || (e >= g->n))) {
        printf("Invaid vertex\n");
        return; 
    }
    node->vertex = e;
    node->link = g->adj_list[s];
    g->adj_list[s] = node;
}

void print_matrix(GraphType* g) {
    for(int r = 0; r < g->n; r++) {
        GraphNode* p = g->adj_list[r];
        printf("%d ", r);
        while(p != NULL) {
            printf(" -> %d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void free_matrix(GraphType* g) {
    for(int r = 0; r < g->n; r++) {
        GraphNode* p = g->adj_list[r];
        while(p != NULL) {
            GraphNode* tp = p;
            p = p->link;
            free(tp);
        }
    }
    free(g);
}

int main() {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    if(g == NULL) {
        exit(1);
    }

    init(g);
    for(int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1); insert_edge(g, 1, 0);
    insert_edge(g, 0, 2); insert_edge(g, 2, 0);
    insert_edge(g, 0, 3); insert_edge(g, 3, 0);
    insert_edge(g, 1, 2); insert_edge(g, 2, 1);
    insert_edge(g, 2, 3); insert_edge(g, 3, 2);

    print_matrix(g);

    free_matrix(g);
    return 0;
}