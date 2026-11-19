#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define INF 10000000
#define true 1
#define false 0

int parent[MAX_VERTICES];

void set_init(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

int set_find(int curr) {
    if(parent[curr] == -1) {
        return curr;
    }
    while(parent[curr] != -1)
        curr = parent[curr];
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent[root1] = root2;
}

typedef struct edge {
    int start;
    int end;
    int weight;
} edge;

typedef struct GraphType {
    int no_v;
    int no_e;
    struct edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g, int v) {
    g->no_v = v;
    g->no_e = 0;
}

void insert_edge(GraphType *g, int start, int end, int w) {
    if(g->no_e >= 2 * MAX_VERTICES) {
        fprintf(stderr, "EDGE OVERFLOW!");
        exit(1);
    }
}