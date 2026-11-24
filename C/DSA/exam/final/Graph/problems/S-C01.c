#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES] = {0}; 

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

void dfs(GraphType *g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    for (w = 0; w < g->n; w++)
        if (g->matrix[v][w] && !visited[w])
            dfs(g, w);
}

int main(void)
{
    FILE *fp;
    GraphType *g;
    int n, m, i, u, v, start;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    g = (GraphType *)malloc(sizeof(GraphType));
    if (g == NULL) {
        fclose(fp);
        return 1;
    }
    init(g);
    fscanf(fp, "%d %d", &n, &m);
    for (i = 0; i < n; i++)
        insert_vertex(g, i);
    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d", &u, &v);
        insert_edge(g, u, v);
    }
    fscanf(fp, "%d", &start);
    fclose(fp);

    printf("깊이 우선 탐색\n");
    dfs(g, start);
    printf("\n");

    free(g);
    return 0;
}