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
    void print() const {
        cout << x << ' ' << y << endl;
    }
    int get_x() const {
        return x;
    }
    int get_y() const {
        return y;
    }
};

const point operator-(const point &arg1, const point &arg2) {
    return point(arg1.get_x() - arg2.get_x(), arg1.get_y() - arg2.get_y());
}

int main() {
    point p1(2, 3), p2(5, 5);
    point p3;

    p3 = p1 - p2;
    p3.print();

    return 0;
}