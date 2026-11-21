#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void insert_sort(int list[], int n) {
    int i, j, key;

    // i = 1부터 n - 1까지 총 (n - 1)번의 패스를 진행
    for (i = 1; i < n; i++) {
        key = list[i];

        // key보다 큰 원소들을 오른쪽으로 한 칸씩 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;

        // 각 단계(round)별 중간 결과 출력
        printf("round %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}

int main(void) {
    int list[MAX_SIZE];
    int n = MAX_SIZE;

    srand((unsigned int)time(NULL));

    printf("before:  ");
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    printf("\n\n");

    insert_sort(list, n);

    return 0;
}