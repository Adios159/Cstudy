#include <stdio.h>
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType *g);

void floyd(GraphType *g)
{
    int i, j, k;
    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            A[i][j] = g->weight[i][j];
    printA(g);
    for (k = 0; k < g->n; k++) {
        for (i = 0; i < g->n; i++)
            for (j = 0; j < g->n; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
        printA(g);
    }
}

void printA(GraphType *g)
{
    int i, j;
    printf("===============================\n");
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (A[i][j] == INF)
                printf("  * ");
            else
                printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
}

int main(void)
{
    GraphType g;
    int edges[8][3] = {
        {0, 1, 3}, {1, 2, 12}, {1, 3, 6}, {2, 1, 5},
        {2, 3, 7}, {3, 0, 2}, {3, 1, 9}, {3, 2, 4}
    };
    int i, j;

    g.n = 4;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.weight[i][j] = (i == j) ? 0 : INF;
    for (i = 0; i < 8; i++)
        g.weight[edges[i][0]][edges[i][1]] = edges[i][2];
    floyd(&g);
    printf("정점 1에서 0까지 최단 거리: %d\n", A[1][0]);
    return 0;
}