#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int data[], int length) {
    int i = 0, j = 0;
    int value = 0;
    for(i = 1;i < length; i++) {
        if(data[i - 1] <= data[i])
            continue;
        value = data[i];
        for(j = 0; j < i; j++) {
            if(data[j] > value) {
                memmove(&data[j + 1], &data[j], sizeof(data[0] * (i - j)));
                data[j] = value;
                break;
            }
        }
    }
}

int main(void) {
    int data[] = {6, 3, 9, 1, 19, 15, 22, 2, 39, 17};
    int length = sizeof(data) / sizeof(data[0]);
    int i = 0;
    printf("before sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    insertion_sort(data, length);
    printf("after sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0; 
}