#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int recursive_max(int arr[], int idx, int length) {
    if(idx == length - 2) {
        return max(arr[idx], arr[idx + 1]);
    }
    return max(arr[idx], recursive_max(arr, idx + 1, length));
}

int main() {
    int arr[10] = {1, 2, 13, 7, 10, 20, 11, 35, 18, 19};
    int ans = recursive_max(arr, 0, 10);
    printf("%d\n", ans);
    return 0;
}