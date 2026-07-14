#include <iostream>
#include <format>
using namespace std;

void swap(int& rx, int& ry) {
    int temp = rx;
    rx = ry;
    ry = temp;
}

int main() {
    int x = 10;
    int y = 20;
    cout << format("before swap: %d, %d\n", x, y);

    swap(x, y);
    cout << format("after swap: %d, %d\n", x, y);
    return 0;
}