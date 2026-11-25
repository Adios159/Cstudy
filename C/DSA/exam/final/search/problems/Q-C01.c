/* data.txt의 첫 줄 n과 이어지는 n개의 정수를 배열에 읽고, 그 뒤 파일 끝까지 읽은 탐색 키마다 순차 탐색을 하여 결과 위치와 키 비교 횟수를 출력한다. 마지막에 성공·실패 횟수를 출력한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int seq_search(int list[], int n, int key, int *cmp)
{
    int i;
    *cmp = 0;
    for (i = 0; i < n; i++) {
        (*cmp)++;
        if (list[i] == key) return i;
    }
    return -1;
}

int main(void)
{
    FILE *fp;
    int list[MAX_SIZE];
    int n, i, key, idx, cmp;
    int found = 0, missed = 0;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    if (fscanf(fp, "%d", &n) != 1 || n > MAX_SIZE) {
        fclose(fp);
        return 1;
    }
    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &list[i]);

    while (fscanf(fp, "%d", &key) == 1) {
        idx = seq_search(list, n, key, &cmp);
        if (idx >= 0) {
            printf("key %d: found at index %d (%d compares)\n", key, idx, cmp);
            found++;
        } else {
            printf("key %d: not found (%d compares)\n", key, cmp);
            missed++;
        }
    }
    fclose(fp);

    printf("found %d, not found %d\n", found, missed);
    return 0;
}
