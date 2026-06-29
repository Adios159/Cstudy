#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int data[], int left, int right) {
    int first = left;
    int pivot = data[first];
    ++left;

    while(left <= right) {
        while(data[left] <= pivot && left < right)
            left++;
         while(data[right] >= pivot && left <= right)
            --right;
        if(left < right)
            swap(&data[left], &data[right]);
        else
            break;
    }
    swap(&data[first], &data[right]);
    return right;
}

void quick_sort(int data[], int left, int right) {
    if(left < right) {
        int index = partition(data, left, right);
        quick_sort(data, left, index - 1);
        quick_sort(data, index + 1, right);
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

    quick_sort(data, 0, length - 1);
    printf("after sort:");
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0; 
}