#include <stdio.h>
#define SIZE 5

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int* ptr = &arr[0];

    for(;;) {
        printf("%d\n", *ptr);
        if(ptr == &arr[SIZE - 1])
            break;
        ptr++;
    }
    return 0;
}