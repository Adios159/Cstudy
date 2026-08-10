#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) {
        this->x = _x;
        this->y = _y;
    }
    void print() {
        cout << x << ' ' << y << endl; 
    }
    const Point operator+(const Point &arg) {
        Point tmp;
        tmp.x = this->x + arg.x;
        tmp.y = this->y + arg.y;
        return tmp;
    }
};

int main() {
    Point p1(2, 3), p2(4, 5);
    Point p3;

    p3 = p1 + p2;
    p3.print();
    return 0;
}