#include <stdio.h>

int* insertation_sort(int arr[], int length) {
    for(int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main(void) {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int length = 6;
    insertation_sort(arr, length);
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}