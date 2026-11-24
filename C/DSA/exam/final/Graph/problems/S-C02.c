/* 같은 그래프를 인접 행렬과 인접 리스트(머리 삽입)에 각각 저장해 DFS 방문 순서가 어떻게 달라지는지 비교한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct MatGraph {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} MatGraph;

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct ListGraph {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} ListGraph;

int visited[MAX_VERTICES];
int order_mat[MAX_VERTICES], order_list[MAX_VERTICES];
int cnt;

void dfs_mat(MatGraph *g, int v, int *order)
{
    int w;
    visited[v] = TRUE;
    order[cnt++] = v;
    for (w = 0; w < g->n; w++)
        if (g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w, order);
}

void dfs_list(ListGraph *g, int v, int *order)
{
    GraphNode *w;
    visited[v] = TRUE;
    order[cnt++] = v;
    for (w = g->adj_list[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs_list(g, w->vertex, order);
}

void add_list(ListGraph *g, int u, int v)
{
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int main(void)
{
    FILE *fp;
    MatGraph *gm;
    ListGraph *gl;
    GraphNode *p, *next;
    int n, m, i, j, u, v, start, same;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    gm = (MatGraph *)malloc(sizeof(MatGraph));
    gl = (ListGraph *)malloc(sizeof(ListGraph));
    if (gm == NULL || gl == NULL) {
        fclose(fp);
        return 1;
    }
    fscanf(fp, "%d %d", &n, &m);
    gm->n = gl->n = n;
    for (i = 0; i < MAX_VERTICES; i++) {
        gl->adj_list[i] = NULL;
        for (j = 0; j < MAX_VERTICES; j++)
            gm->adj_mat[i][j] = 0;
    }
    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d", &u, &v);
        gm->adj_mat[u][v] = gm->adj_mat[v][u] = 1;
        add_list(gl, u, v);
        add_list(gl, v, u);
    }
    fscanf(fp, "%d", &start);
    fclose(fp);

    cnt = 0;
    dfs_mat(gm, start, order_mat);
    for (i = 0; i < n; i++)
        visited[i] = FALSE;
    cnt = 0;
    dfs_list(gl, start, order_list);

    printf("행렬 DFS:");
    for (i = 0; i < n; i++)
        printf(" %d", order_mat[i]);
    printf("\n리스트 DFS:");
    for (i = 0; i < n; i++)
        printf(" %d", order_list[i]);
    printf("\n");
    same = 1;
    for (i = 0; i < n; i++)
        if (order_mat[i] != order_list[i])
            same = 0;
    printf(same ? "방문 순서 같음\n" : "방문 순서 다름\n");

    for (i = 0; i < n; i++) {
        p = gl->adj_list[i];
        while (p != NULL) {
            next = p->link;
            free(p);
            p = next;
        }
    }
    free(gm);
    free(gl);
    return 0;
}
