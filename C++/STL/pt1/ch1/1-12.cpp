#include <iostream>
using namespace std;

class point {
    int x;
    int y;
public:
    point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void print() {
        cout << x << ' ' << y << endl; 
    }
};

class point_ptr {
    point *ptr;
public:
    point_ptr(point *p) : ptr(p) {

    }
    ~point_ptr() {
        delete ptr;
    }

    point* operator->() const {
        return ptr;
    }
};

int main() {
    point_ptr p1 = new point(2, 3);
    point_ptr p2 = new point(5, 5);

    p1->print();
    p2->print();

    return 0;
}