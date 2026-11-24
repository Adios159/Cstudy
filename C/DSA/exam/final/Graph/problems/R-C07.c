/* 여러 그래프를 읽어 서로 다른 간선의 수가 n(n-1)/2인지 비교하여 완전 그래프 여부를 판별한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType *g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType *g, int v)
{
    if (v >= MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType *g)
{
    int i, j;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++)
            printf("%2d ", g->adj_mat[i][j]);
        printf("\n");
    }
}

int count_edges(GraphType *g)
{
    int i, j, cnt = 0;
    for (i = 0; i < g->n; i++)
        for (j = i + 1; j < g->n; j++)
            if (g->adj_mat[i][j])
                cnt++;
    return cnt;
}

int main(void)
{
    FILE *fp;
    GraphType *g;
    int t, k, n, m, i, u, v;
    int edges, need;

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
    fscanf(fp, "%d", &t);
    for (k = 1; k <= t; k++) {
        init(g);
        fscanf(fp, "%d %d", &n, &m);
        for (i = 0; i < n; i++)
            insert_vertex(g, i);
        for (i = 0; i < m; i++) {
            fscanf(fp, "%d %d", &u, &v);
            insert_edge(g, u, v);
        }
        edges = count_edges(g);
        need = n * (n - 1) / 2;
        printf("그래프 %d: n=%d, 간선 %d개, 필요 %d개 -> ", k, n, edges, need);
        if (edges == need)
            printf("완전 그래프\n");
        else
            printf("완전 그래프 아님\n");
    }
    fclose(fp);

    free(g);
    return 0;
}
