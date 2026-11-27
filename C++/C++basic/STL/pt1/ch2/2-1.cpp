#include <iostream>
using namespace std;

void Print(int n) {
    cout << n << endl;
}

int main() {
    void (*pf)(int);
    pf = Print;

    Print(10);
    pf(10);
    (*pf)(10);

    return 0;
}