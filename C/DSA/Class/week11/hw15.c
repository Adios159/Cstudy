#include <stdio.h>

#define N 6
#define INF 1000000000

int d[N][N];

void setEdge(int a, int b, int w) {
    d[a][b] = w;
}

int main(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }

    setEdge(0, 1, 3);
    setEdge(1, 0, 8);
    setEdge(1, 2, 2);
    setEdge(2, 3, 1);
    setEdge(2, 5, 6);
    setEdge(5, 2, 9);
    setEdge(4, 2, 3);
    setEdge(3, 0, 2);
    setEdge(0, 3, 7);
    setEdge(3, 4, 4);
    setEdge(4, 5, 2);
    setEdge(5, 4, 1);

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    printf("[모든 정점 쌍 최단 거리]\n");
    printf("    ");
    for (int j = 0; j < N; j++) printf("%4d", j);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < N; j++) printf("%4d", d[i][j]);
        printf("\n");
    }

    printf("\n[정점별 배송 거리 합]\n");
    int best = 0;
    int bestSum = INF;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) sum += d[i][j];
        printf("정점 %d : %d\n", i, sum);
        if (sum < bestSum) {
            bestSum = sum;
            best = i;
        }
    }

    printf("\n물류센터 위치: 정점 %d, 거리 합 %d\n", best, bestSum);

    return 0;
}