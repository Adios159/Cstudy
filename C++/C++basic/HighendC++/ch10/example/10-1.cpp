#include <iostream>
using namespace std;

class Circle {
    private:
        int radius;
    public:
        Circle(int radius = 1) { this->radius = radius; }
        int getRadius() { return radius; }
};

template <class T>
void myswap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 4, b = 5;
    myswap(a, b);
    cout << a << b << endl;

    float c = 0.2, d = 0.4;
    myswap(c, d);
    cout << c << d << endl;

    return 0;
}