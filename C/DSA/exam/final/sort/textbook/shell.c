#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_SIZE = 10;

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++) {
            inc_insertion_sort(list, i, n - 1, gap);
        }
        printf("gap %d: ", gap);
        for(int j = 0; j < n; j++) {
            printf("%d ", list[j]);
        }
        printf("\n");
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
    printf("\n");

    shell_sort(list, n);

    return 0;
}