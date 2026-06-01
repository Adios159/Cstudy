#include <iostream>
using namespace std;

int main() {
    int arr[10];

    for(int i = 0; i < 10; i += 2) {
        arr[i] = 0;
    }
    for(int j = 1; j < 10; j += 2) {
        arr[j] = 1;
    }
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
    return 0;
}