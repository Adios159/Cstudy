#include <iostream>
using namespace std;

struct func_object {
public:
    void operator() (int arg) const {
        cout << "num: " << arg << endl;
    }
    void operator() (int arg1, int arg2) const {
        cout << "num: " << arg1 << ", " << arg2 << endl;
    }
    void operator() (int arg1, int arg2, int arg3) const {
        cout << "num: " << arg1 << ", " << arg2 << ", " << arg3 << endl;
    }
};

int main() {
    func_object print;
    print(10);
    print(10, 20);
    print(10, 20, 30);
    cout << endl;

    print.operator()(10);
    print.operator()(10, 20);
    print.operator()(10, 20, 30);
}