#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 102
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

int main(void) {
    int i, j, least, temp, cmp = 0, swap = 0;
    int idx = 0;
    FILE *fp = fopen("data.txt", "r");
    while(n < MAX_SIZE && fscanf(fp, "%d", &list[n]) == 1) {
        n++;
    }
    for(i = 0; i < n - 1; i++) {
        least = i;
        for(j = i + 1; j < n; j++) {
            if(list[j] < list[least]) {
                least = j;
                cmp++;
            }
        }
        SWAP(list[i], list[least], temp);
        swap++;
    }
    printf("n = %d\n", n);
    printf("compare: %d\n", cmp);
    printf("swap: %d\n", swap);
    printf("result: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}