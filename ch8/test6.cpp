#include <iostream>
using namespace std;

bool isSameArr(int arr1[], int arr2[]) {
    if(sizeof(arr1) != sizeof(arr2)) {
        return false;
    }
    for(int i = 0; i < sizeof(arr1); i++) {
        if(arr1[i] == arr2[i]) {
            return true;
        }

        else {
            return false;
        }
    }
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {2, 3, 4, 5, 6};
    int arr4[6] = {0, 0, 0, 0, 0, 0};

    isSameArr(arr1, arr2);
    isSameArr(arr2, arr3);
    isSameArr(arr3, arr4);

    return 0;
}