#include <stdio.h>

#define N 7
#define INF 1000000000

int g[N][N];

void addEdge(int a, int b, int w) {
    g[a][b] = w;
    g[b][a] = w;
}

void dijkstra(int s, int dist[]) {
    int visited[N] = {0};
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[s] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
        if (u == -1 || dist[u] == INF) break;
        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (g[u][v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
}

int main(void) {
    addEdge(1, 2, 4);
    addEdge(1, 0, 7);
    addEdge(1, 4, 2);
    addEdge(1, 5, 6);
    addEdge(0, 5, 10);
    addEdge(0, 4, 3);
    addEdge(5, 4, 5);
    addEdge(2, 3, 9);
    addEdge(4, 3, 11);
    addEdge(4, 6, 5);
    addEdge(3, 6, 4);

    int s, via, e;
    printf("출발 정점, 경유 정점, 도착 정점: ");
    if (scanf("%d %d %d", &s, &via, &e) != 3) return 1;
    if (s < 0 || s >= N || via < 0 || via >= N || e < 0 || e >= N) {
        printf("정점 번호는 0~%d 범위여야 합니다.\n", N - 1);
        return 1;
    }

    int fromS[N], fromVia[N];
    dijkstra(s, fromS);
    dijkstra(via, fromVia);

    int direct = fromS[e];
    int first = fromS[via];
    int second = fromVia[e];
    int total = first + second;

    printf("직행    %d -> %d       : %d\n", s, e, direct);
    printf("경유    %d -> %d -> %d    : %d + %d = %d\n", s, via, e, first, second, total);
    printf("추가 거리               : %d\n", total - direct);

    return 0;
}