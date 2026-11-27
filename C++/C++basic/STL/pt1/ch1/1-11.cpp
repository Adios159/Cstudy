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
    Point *p1 = new Point(2, 3);
    Point *p2 = new Point(5, 5);

    p1->print();
    p2->print();

    delete p1;
    delete p2;

    return 0;
}