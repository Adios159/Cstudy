/* data.txt의 첫 줄 n과 이어지는 n개의 정수를 읽어 합병 정렬(merge_sort)한다.
   merge가 끝날 때마다 구간과 배열 전체를 출력한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int sorted[MAX_SIZE];
int total;

void print_list(int list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
        printf("merge [%d..%d]: ", left, right);
        print_list(list, total);
    }
}

int main(void)
{
    FILE *fp;
    int list[MAX_SIZE];
    int n, i;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    if (fscanf(fp, "%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        fclose(fp);
        return 1;
    }
    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &list[i]);
    fclose(fp);

    total = n;
    printf("before: ");
    print_list(list, n);
    merge_sort(list, 0, n - 1);
    printf("after: ");
    print_list(list, n);
    return 0;
}
