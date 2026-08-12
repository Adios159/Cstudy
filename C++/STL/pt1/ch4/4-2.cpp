#include <iostream>
using namespace std;

template <typename T1, typename T2>
void Print(T1 a, T2 b) {
    cout << a << ' ' << b << endl;
}

int main() {
    Print(10, 0.1);
    Print("Banana: ", 10);

    return 0;
}