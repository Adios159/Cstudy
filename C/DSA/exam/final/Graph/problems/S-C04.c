/* 강의의 bfs 방식대로 원형 큐에 정점을 넣고 빼면서 인접 행렬 그래프를 너비 우선으로 탐색한다. */
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

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void queue_init(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

int is_full(QueueType *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q)) {
        fprintf(stderr, "큐가 포화상태입니다\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q)) {
        fprintf(stderr, "큐가 공백상태입니다\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void bfs_mat(GraphType *g, int v)
{
    int w;
    QueueType q;
    queue_init(&q);
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = 0; w < g->n; w++)
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;
                printf("%d 방문 -> ", w);
                enqueue(&q, w);
            }
    }
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

    printf("너비 우선 탐색\n");
    bfs_mat(g, start);
    printf("\n");

    free(g);
    return 0;
}
