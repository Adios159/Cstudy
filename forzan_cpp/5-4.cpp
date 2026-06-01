#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
    if(a > b) {
        big = a;
        return true;
    }
    big = b;
    return false;
}

int main() {
    int a = 3;
    int b = 5;
    int num = 0;
    int* big = &num;
    cout << bigger(a, b, *big) << ' ' << num << endl;

    return 0;
}