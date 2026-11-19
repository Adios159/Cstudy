#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 50
#define MAX_VERTICES 100
#define true 1
#define false 0

int visited[MAX_VERTICES];

typedef int element;
typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* list[MAX_VERTICES];
} GraphType;

typedef struct QueueType {
    element queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element data) {
    if(is_full(q)) {
        error("QUEUE OVERFLOW!\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = data;
}

element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("QUEUE IS EMPTY!\n");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

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

void bfs(GraphType *g, int v) {
    GraphNode* w;
    QueueType q;

    queue_init(&q);
    visited[v] = true;
    printf("visited #%d -> ", v);
    enqueue(&q, v);
    while(!is_empty(&q)) {
        v = dequeue(&q);
        for(w = g->list[v]; w; w = w->link) {
            if(!visited[w->vertex]) {
                visited[w->vertex] = true;
                printf(" #%d -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
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
    for(int i = 0; i < 6; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    print_list(g);
    printf("\n");

    bfs(g, 0);
    printf("\n");

    free(g);
    return 0;
}