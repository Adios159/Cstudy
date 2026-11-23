#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1001

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        exit(1);
    }

    int list[MAX_SIZE];
    int n;
    fscanf(fp, "%d", &n);
    for(int k = 0; k < n; k++) {
        fscanf(fp, "%d", &list[k]);
    }

    int i, j, key, cmp = 0, change = 0;
    fclose(fp);
    // i = 1부터 n - 1까지 총 (n - 1)번의 패스를 진행
    for (i = 1; i < n; i++) {
        key = list[i];

        // key보다 큰 원소들을 오른쪽으로 한 칸씩 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            cmp++;
            list[j + 1] = list[j];
            change++;
        }
        list[j + 1] = key;
    }

    printf("result: ");
    for(int k = 0; k < n; k++) {
        printf("%d ", list[k]);
    }

    printf("\ncompare: %d\n", cmp);
    printf("change: %d\n", change);
    return 0;
}