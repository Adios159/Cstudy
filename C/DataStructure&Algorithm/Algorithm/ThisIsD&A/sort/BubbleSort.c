#include <stdio.h>

void bubble_sort(int data[], int length) {
    int i = 0, j = 0;
    int temp = 0;
    for(int i = 0; i < length - 1; i++) {
        for(j = 0; j < length - (i + 1); j++) {
            if(data[j] > data[j + 1]) {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main(void) {
    int data[] = {6, 3, 9, 1, 19, 15, 22};
    int length = sizeof(data) / sizeof(data[0]);
    int i = 0;
    printf("before sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    bubble_sort(data, length);
    printf("after sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0; 
}