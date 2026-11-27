#include <iostream>
using namespace std;

void Print(int n) {
    cout << "Global: " << n << endl;
}

namespace A {
    void Print(int n) {
        cout << "namespace: " << n << endl;
    }
}

class C {
public:
    static void Print(int n) {
        cout << "class: " << n << endl;
    }
};

int main() {
    void (*pf)(int);

    Print(10);
    A::Print(10);
    C::Print(10);
    cout << endl;

    pf = Print;
    pf(10);
    pf = A::Print;
    pf(10);
    pf = C::Print;
    pf(10);

    return 0;
}