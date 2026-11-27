#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s);
int is_empty(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);


void init(StackType *s) { s->top = -1; }
int is_empty(StackType *s) { return s->top == -1; }
int is_full(StackType *s) { return s->top == MAX_STACK_SIZE - 1; }

void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->stack[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

void graph_init(GraphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v)
{
    (void)v;
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int topo_sort(GraphType *g)
{
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int *)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
        in_degree[i] = 0;
    for (i = 0; i < g->n; i++) {
        GraphNode *node = g->adj_list[i];
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    init(&s);
    for (i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) push(&s, i);
    }
    while (!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("정점 %d ->", w);
        node = g->adj_list[w];
        while (node != NULL) {
            int u = node->vertex;
            in_degree[u]--;
            if (in_degree[u] == 0) push(&s, u);
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}

int main(void)
{
    GraphType g;
    int edges[8][2] = { {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 3}, {2, 5}, {3, 5}, {4, 5} };
    int i;
    GraphNode *node, *next;

    graph_init(&g);
    for (i = 0; i < 6; i++)
        insert_vertex(&g, i);
    for (i = 0; i < 8; i++)
        insert_edge(&g, edges[i][0], edges[i][1]);
    printf("반환값: %d\n", topo_sort(&g));
    insert_edge(&g, 5, 0);
    printf("간선 <5,0> 추가 후 반환값: %d\n", topo_sort(&g));
    for (i = 0; i < g.n; i++)
        for (node = g.adj_list[i]; node != NULL; node = next) {
            next = node->link;
            free(node);
        }
    return 0;
}

