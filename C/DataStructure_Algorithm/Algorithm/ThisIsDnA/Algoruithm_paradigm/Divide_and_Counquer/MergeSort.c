#include <stdio.h>
#include <stdlib.h>

void merge_sort(int data[], int start, int end) {
    int middle;
    if(end - start < 1) {
        return;
    }
    middle = (start + end) / 2;
    merge_sort(data, start, middle);
    merge_sort(data, middle + 1, end);
    merge(data, start, middle, end);
}

void merge(int data[], int start, int middle, int end) {
    int i;
    int left = start;
    int right = middle + 1;
    int dest = 0;

    int* destination = (int*)malloc(sizeof(int) * (end - start + 1));

    while(left <= middle && right <= end) {
        if(data[left] < data[right]) {
            destination[dest] = data[left];
            left++;
        }
        else {
            destination[dest] = data[right];
            right++;
        }
        dest++;
    }

    while(left <= middle) {
        destination[dest++] = data[left++];
    }
    while(right <= end) {
        destination[dest++] = data[right++];
    }

    dest = 0;
    for(i = start; i <= end; i++) {
        data[i] = destination[dest++];
    }
    free(destination);
}

int main(void) {
    int data[] = {112, 3, 45, 6, 7, 89, 114, 79, 64, 468};
    int length = sizeof data / sizeof data[0];
    int i = 0;

    merge_sort(data, 0, length - 1);
    for(i = 0; i < length; i++) {
        printf("%d ", data[i]); 
    }
    printf("\n");
    return 0;
}