#include <iostream>
using namespace std;

void Print() {
    cout << "Hello World" << endl; 
}

class cl {
public:
    void Print() {
        cout << "Hello World" << endl; 
    }
};

int main() {
    cl cla;
    cl *clap = &cla;

    Print();
    cla.Print();
    clap->Print();

    return 0;
}