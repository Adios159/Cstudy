#include <stdio.h>
#include <stdlib.h>
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
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        exit(1);
    }

    int vertex, edge, start, end, query;
    fscanf(fp, "%d %d", &vertex, &edge);

    for(int i = 0; i < vertex; i++) {
        insert_vertex(g, i);
    }
    for(int i = 0; i < edge; i++) {
        fscanf(fp, "%d %d", &start, &end);
        insert_edge(g, start, end);
    }

    fscanf(fp, "%d", &query);
    for(int i = 0; i < query; i++) {
        GraphNode* temp = NULL;
        fscanf(fp, "%d %d", &start, &end);
        temp = g->list[start];
        while(temp != NULL) {
            if(temp->vertex == end) {
                printf("(%d %d): Y\n", start, end);
                break;
            }
            else {
                temp = temp->link;
            }
        }
        if(temp == NULL) {
            printf("(%d %d): N\n", start, end);
        }
    }
    fclose(fp);
    free(g);
    return 0;
}