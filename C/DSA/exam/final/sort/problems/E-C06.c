/* data.txt의 여러 테스트 케이스마다 버블 정렬을 내림차순으로 수행하여
   조기 종료(flag) 버전과 일반 버전의 패스 수를 비교한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

int bubble_sort_desc(int list[], int n)
{
    int i, j, temp, passes = 0;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++)
            if (list[j] < list[j + 1])
                SWAP(list[j], list[j + 1], temp);
        passes++;
    }
    return passes;
}

int bubble_sort_flag(int list[], int n)
{
    int i, j, temp, flag, passes = 0;
    for (i = n - 1; i > 0; i--) {
        flag = 0;
        for (j = 0; j < i; j++)
            if (list[j] < list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                flag = 1;
            }
        passes++;
        if (flag == 0) break;
    }
    return passes;
}

int main(void)
{
    FILE *fp;
    int a[MAX_SIZE], b[MAX_SIZE];
    int t, c, n, i, p1, p2;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    if (fscanf(fp, "%d", &t) != 1) {
        fclose(fp);
        return 1;
    }
    for (c = 1; c <= t; c++) {
        fscanf(fp, "%d", &n);
        if (n > MAX_SIZE) break;
        for (i = 0; i < n; i++) {
            fscanf(fp, "%d", &a[i]);
            b[i] = a[i];
        }
        p1 = bubble_sort_desc(a, n);
        p2 = bubble_sort_flag(b, n);
        printf("case %d: 일반 %d패스, flag %d패스 -> ", c, p1, p2);
        print_list(b, n);
    }
    fclose(fp);
    return 0;
}
