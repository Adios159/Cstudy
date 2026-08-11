#include <iostream>
using namespace std;

struct func_object {
public:
    void operator() (int arg) {
        cout << "num: " << arg << endl;
    }
};

void print1(int arg) {
    cout << "num: " << arg << endl;
}

int main() {
    void (*print2)(int) = print1;
    func_object print3;
    
    print1(10);
    print2(20);
    print3(30);

    return 0;
}