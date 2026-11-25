#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 10

int step = 1; // 단계 카운트용 전역 변수

// 배열의 현재 상태와 피벗 위치를 출력하는 헬퍼 함수
void print_step(int list[], int left, int right, int pivot_idx) {
    printf("[Step %2d] (범위: %d~%d, 피벗값: %d) -> ", step++, left, right, list[pivot_idx]);
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == pivot_idx)
            printf("[%d] ", list[i]); // 자리 잡은 피벗은 대괄호로 강조
        else
            printf("%d ", list[i]);
    }
    printf("\n");
}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while (low <= right && list[low] < pivot);
        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high);
    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right);
        
        // 파티션 직후 확정된 피벗 위치(q)와 배열 상태 출력
        print_step(list, left, right, q);

        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main(void) {
    int list[MAX_SIZE];
    int n = MAX_SIZE;

    srand((unsigned int)time(NULL));

    printf("before: ");
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    printf("\n\n");

    quick_sort(list, 0, n - 1); // n - 1로 수정

    printf("\nafter:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}