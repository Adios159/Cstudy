#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct GraphType {
    int n;
    int matrix[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType *g) {
    int r, c;
    g->n = 0;
    for(r = 0; r < MAX_VERTICES; r++) {
        for(c = 0; c < MAX_VERTICES; c++) {
            g->matrix[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "VERTEX OVERFLOW!");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "No EXIST VERTEX!");
        return;
    }
    g->matrix[start][end] = 1;
    g->matrix[end][start] = 1;
}

void print_matrix(GraphType *g) {
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            printf("%2d", g->matrix[i][j]);
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
    print_matrix(g);

    free(g);
    return 0;
}