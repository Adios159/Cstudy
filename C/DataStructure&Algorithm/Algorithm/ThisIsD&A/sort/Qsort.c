#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_point(const void* _elem1, const void* _elem2) {
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if(*elem1 > *elem2)
        return 1;
    else if(*elem1 < *elem2)
        return -1;
    else
        return 0;
}

int main(void) {
    int data[] = {6, 8, 1, 4, 13, 15};
    int length = sizeof(data) / sizeof(data[0]);
    int i = 0;
    printf("before sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    qsort((void*)data, length, sizeof(int), compare_point);
    printf("After sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}