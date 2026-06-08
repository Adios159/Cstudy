#include <iostream>
#include <cstdio>
using namespace std;

class Vector {
    int* mem;
    int size;
public:
    Vector();
    Vector(int size, int init);
    void show();
    void show(int len);
};

Vector::Vector() {
    mem = new int[5];
    for(int i = 0; i< 5; i++) {
        mem[i] = 0;
    }
    this->size = 5;
}

Vector::Vector(int size, int init) {
    this->size = size;
    mem = new int[size];
    for(int i = 0; i< size; i++) {
        mem[i] = init;
    }
}

void Vector::show() {
    for(int i = 0; i < size; i++) {
        cout << mem[i] << ' ';
    }
    cout << endl;
}

void Vector::show(int len) {
    if(len > size){
        cout << "error" << endl;
        return;
    }
    for(int i = 0; i < len; i++) {
        cout << mem[i] << ' ';
    }
    cout << endl;
}

int main() {
    Vector x;
    Vector y(10, 8);
    x.show();
    y.show();
    y.show(4);
    x.show(11);

    return 0;
}