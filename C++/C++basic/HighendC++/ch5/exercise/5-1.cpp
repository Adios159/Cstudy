#include <iostream>
using namespace std;

int twice(int *num) {
    return *num = *num * 2;
}

int main() {
    int n = 12;
    twice(&n);
    cout << n << endl;

    return 0;
}