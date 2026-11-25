/* 재귀 없이 스택을 사용하는 DFS-iterative를 구현하고, 재귀 DFS와 방문 순서를 비교한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v)
{
    if (v >= MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType *g)
{
    int i;
    GraphNode *p;
    for (i = 0; i < g->n; i++) {
        p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void free_graph(GraphType *g)
{
    int i;
    GraphNode *p, *next;
    for (i = 0; i < g->n; i++) {
        p = g->adj_list[i];
        while (p != NULL) {
            next = p->link;
            free(p);
            p = next;
        }
        g->adj_list[i] = NULL;
    }
}

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty_stack(StackType *s)
{
    return s->top == -1;
}

void push(StackType *s, int item)
{
    if (s->top >= MAX_STACK_SIZE - 1) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

int pop(StackType *s)
{
    if (is_empty_stack(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

void dfs_list(GraphType *g, int v)
{
    GraphNode *w;
    visited[v] = TRUE;
    printf(" %d", v);
    for (w = g->adj_list[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs_list(g, w->vertex);
}

void dfs_iterative(GraphType *g, int v)
{
    StackType s;
    GraphNode *w;
    int max_size = 1;
    init_stack(&s);
    push(&s, v);
    while (!is_empty_stack(&s)) {
        v = pop(&s);
        if (!visited[v]) {
            visited[v] = TRUE;
            printf(" %d", v);
        }
        for (w = g->adj_list[v]; w; w = w->link)
            if (!visited[w->vertex])
                push(&s, w->vertex);
        if (s.top + 1 > max_size)
            max_size = s.top + 1;
    }
    printf("\n스택 최대 크기: %d\n", max_size);
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
        insert_edge(g, v, u);
    }
    fscanf(fp, "%d", &start);
    fclose(fp);

    printf("스택 DFS:");
    dfs_iterative(g, start);

    for (i = 0; i < n; i++)
        visited[i] = FALSE;
    printf("재귀 DFS:");
    dfs_list(g, start);
    printf("\n");

    free_graph(g);
    free(g);
    return 0;
}
