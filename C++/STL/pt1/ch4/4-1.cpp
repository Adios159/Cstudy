#include <iostream>
using namespace std;

template<typename T>
void Print(T a, T b) {
    cout << a << ' ' << b << endl;
}

int main() {
    Print(10, 20);
    Print(0.123, 0.345);
    Print("Apple", "Banana");

    return 0;
}