#define _CRT_SECURE_NO_WARNINGS
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

// BFS용 원형 큐 구조체 정의
typedef struct {
    int data[MAX_VERTICES];
    int front;
    int rear;
} QueueType;

void queue_init(QueueType* q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType* q) {
    return q->front == q->rear;
}

void enqueue(QueueType* q, int item) {
    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->data[q->rear] = item;
}

int dequeue(QueueType* q) {
    q->front = (q->front + 1) % MAX_VERTICES;
    return q->data[q->front];
}

int visited[MAX_VERTICES] = {0};

void init(GraphType* g) {
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if((g->n) + 1 > MAX_VERTICES) {
        printf("MAX VERTICES\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int s, int e) {
    if(((s < 0) || (s >= g->n)) || ((e < 0) || (e >= g->n))) {
        printf("Invalid vertex\n");
        return; 
    }
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = e;
    node->link = g->adj_list[s];
    g->adj_list[s] = node;
}

void print_list(GraphType* g) {
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

void dfs_list(GraphType* g, int v) {
    visited[v] = 1;
    printf("edge %d -> ", v);
    for(GraphNode* w = g->adj_list[v]; w != NULL; w = w->link) {
        if(!visited[w->vertex]) {
            dfs_list(g, w->vertex);
        }
    }
}

void bfs_list(GraphType* g, int v) {
    QueueType q;
    queue_init(&q);

    visited[v] = 1;
    printf("edge %d -> ", v);
    enqueue(&q, v);

    while(!is_empty(&q)) {
        int u = dequeue(&q);
        for(GraphNode* w = g->adj_list[u]; w != NULL; w = w->link) {
            if(!visited[w->vertex]) {
                visited[w->vertex] = 1;
                printf("edge %d -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}

void reset_visited() {
    for(int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }
}

void free_graph(GraphType* g) {
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

    printf("--- 인접 리스트 출력 ---\n");
    print_list(g);

    printf("\n--- DFS 탐색 결과 ---\n");
    dfs_list(g, 0);
    printf("\n");

    // DFS 이후 BFS 실행 전 방문 배열 초기화 필수
    reset_visited();

    printf("\n--- BFS 탐색 결과 ---\n");
    bfs_list(g, 0);
    printf("\n");

    free_graph(g);
    return 0;
}