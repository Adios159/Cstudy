/* data.txt의 정수를 삽입 정렬(오름차순)하면서 원소 비교 횟수와
   원소 이동 횟수(오른쪽으로 한 칸 밀기)를 각각 센다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void insertion_sort(int list[], int n, int *comp, int *move)
{
    int i, j, key;
    *comp = 0;
    *move = 0;
    for (i = 1; i < n; i++) {
        key = list[i];
        j = i - 1;
        while (j >= 0) {
            (*comp)++;
            if (list[j] > key) {
                list[j + 1] = list[j];
                (*move)++;
                j--;
            }
            else break;
        }
        list[j + 1] = key;
    }
}

int main(void)
{
    FILE *fp;
    int list[MAX_SIZE];
    int n, i, comp, move;

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
    fclose(fp);

    insertion_sort(list, n, &comp, &move);
    printf("비교 횟수: %d\n", comp);
    printf("이동 횟수: %d\n", move);
    printf("결과: ");
    print_list(list, n);
    return 0;
}
