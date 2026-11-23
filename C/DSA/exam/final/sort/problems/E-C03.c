#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n) {
    int i, j, temp;
    for(i = n - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(list[j] > list[j + 1]) 
                SWAP(list[j], list[j + 1], temp);
        }
        printf("round %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}


int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    printf("before: ");
    for(i = 0; i < n; i++) {
        list[i] = rand() % 1000; 
        printf("%d ", list[i]);
    }
    printf("\n");

    bubble_sort(list, n);
    printf("\n");
    return 0;
}