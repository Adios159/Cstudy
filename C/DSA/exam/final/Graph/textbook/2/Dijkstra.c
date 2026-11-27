#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void print_status(GraphType *g);

#define INF 1000000

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

void shortest_path(GraphType *g, int start)
{
    int i, u, w;
    for (i = 0; i < g->n; i++) {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;
    for (i = 0; i < g->n - 1; i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w < g->n; w++)
            if (!found[w])
                if (distance[u] + g->weight[u][w] < distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}

void print_status(GraphType *g)
{
    static int step = 1;
    int i;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("        found:    ");
    for (i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

int main(void)
{
    GraphType g;
    int edges[12][3] = {
        {0, 1, 7}, {0, 4, 3}, {0, 5, 10}, {1, 2, 4}, {1, 3, 10}, {1, 4, 2},
        {1, 5, 6}, {2, 3, 2}, {3, 4, 11}, {3, 5, 9}, {3, 6, 4}, {4, 6, 5}
    };
    int i, j;

    g.n = 7;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.weight[i][j] = (i == j) ? 0 : INF;
    for (i = 0; i < 12; i++) {
        g.weight[edges[i][0]][edges[i][1]] = edges[i][2];
        g.weight[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    shortest_path(&g, 0);
    printf("최종 distance:");
    for (i = 0; i < g.n; i++)
        printf(" %d", distance[i]);
    printf("\n");
    return 0;
}