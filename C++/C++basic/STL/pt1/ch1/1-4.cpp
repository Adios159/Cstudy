#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void print() {
        cout << x << ' ' << y << endl; 
    }
    const Point operator--(int) {
        Point pt(x, y);
        --x;
        --y;
        return pt;
    }
    const Point operator--() {
        Point pt(x, y);
        --x;
        --y;
        return pt;
    }
};

int main() {
    Point p1(2, 3), p2(5, 5);
    Point result;

    result = --p1;
    p1.print();
    result.print();

    result = p2--;
    p2.print();
    result.print();
}