#include <iostream>
using namespace std;

int add(int arr[], int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum;
}
int add(int arr[], int num1, int num2) {
    int sum = 0;
    for(int i = 0; i < num1; i++) {
        sum += arr[i];
    }
    sum += num2;
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4 ,5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, 5);
    int d = add(b, 3, c);
    cout << c << ' ' << d << endl;

    return 0;
}