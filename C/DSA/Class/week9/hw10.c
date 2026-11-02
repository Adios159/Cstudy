#define CRT_SECUER_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct GraphType {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int n;
} GraphType;

void init(GraphType* g) {
    g->n = 0;
    for(int r = 0; r < MAX_VERTICES; r++) {
        for(int c = 0; c < MAX_VERTICES; c++) {
            g->matrix[r][c] = 0;
        }
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
    if(((s < 0) || (s >= g->n)) || ((e < 0) || (e >= g->n))) {
        printf("Invaid vertex\n");
        return; 
    }
    g->matrix[s][e] = 1;
    g->matrix[e][s] = 1;
}

void print_matrix(GraphType* g) {
    for(int r = 0; r < g->n; r++) {
        for(int c = 0; c < g->n; c++) {
            printf("%2d ", g->matrix[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    if(g == NULL) {
        exit(1);
    }

    init(g);
    for(int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    print_matrix(g);

    free(g);
    return 0;
}