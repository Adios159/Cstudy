#include <iostream>
using namespace std;

void Print() {
    cout << "global" << endl;
}

struct Functor
{
    void operator() () {
        cout << "function object" << endl;
    }
};


int main() {
    Functor func;
    Print();
    func();

    return 0;
}