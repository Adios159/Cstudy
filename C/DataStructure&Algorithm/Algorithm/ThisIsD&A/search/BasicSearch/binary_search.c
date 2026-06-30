#include <stdlib.h>
#include <stdio.h>

int* binary_search(int arr[], int size, int target) {
    int left, right, mid;
    left = 0;
    right = size - 1;

    while(left <= right) {
        mid = (left + right) / 2;
        if(target == arr[mid])
            return &(arr[mid]);
        else if(target > arr[mid]) {
            left = mid + 1;
        }
        else    
            right = mid - 1;
    }
    return NULL;
}

int compare_point(const void* _elem1, const void* _elem2) {
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if(elem1 > elem2) {
        return 1;
    }
    else if(elem1 < elem2) {
        return -1;
    }
    else
        return 0;
}

int main(void) {
    int arr[] = {12, 1, 48, 5, 9, 20, 17, 49, 28, 33};
    int length = sizeof(arr) / sizeof(arr[0]);
    qsort((void*)arr, length, sizeof(int), compare_point);

    int* found = binary_search(arr, length, 20);
    printf("location of 20: %p\n", found);

    return 0;
}