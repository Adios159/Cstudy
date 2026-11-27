#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init_graph(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (g->n + 1 > MAX_VERTICES) return;
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void topo_sort(GraphType* g) {
    int in_degree[MAX_VERTICES] = { 0 };
    int stack[MAX_VERTICES];
    int top = -1;

    for (int i = 0; i < g->n; i++) {
        GraphNode* node = g->adj_list[i];
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    for (int i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) {
            stack[++top] = i;
        }
    }

    printf("위상 정렬 순서: ");
    while (top != -1) {
        int w = stack[top--];
        printf("%d", w);
        if (top != -1 || g->adj_list[w] != NULL) {
            printf(" -> ");
        }

        GraphNode* node = g->adj_list[w];
        while (node != NULL) {
            int u = node->vertex;
            in_degree[u]--;
            if (in_degree[u] == 0) {
                stack[++top] = u;
            }
            node = node->link;
        }
    }
    printf("\n");
}

int main() {
    FILE* fp = fopen("data2.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    GraphType g;
    init_graph(&g);

    char type;
    int u, v;
    while (fscanf(fp, " %c", &type) != EOF) {
        if (type == 'v') {
            fscanf(fp, "%d", &u);
            insert_vertex(&g, u);
        } else if (type == 'e') {
            fscanf(fp, "%d %d", &u, &v);
            insert_edge(&g, u, v);
        }
    }
    fclose(fp);

    topo_sort(&g);

    for (int i = 0; i < g.n; i++) {
        GraphNode* curr = g.adj_list[i];
        while (curr != NULL) {
            GraphNode* temp = curr;
            curr = curr->link;
            free(temp);
        }
    }

    return 0;
}