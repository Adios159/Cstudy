#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius) {this->radius = radius;}
    Circle& plus(int n) {
        radius += n;
        return *this;
    }
    int getRadius() {return radius;}
};

int main() {
    Circle a(5);
    a.plus(1).plus(2).plus(3);
    cout << "radius of a: " << a.getRadius();

    return 0;
}