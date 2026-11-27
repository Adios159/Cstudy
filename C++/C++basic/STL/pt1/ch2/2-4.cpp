#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    explicit Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void Print() const { cout << x << ' ' << y << endl; }
    void print_int(int a) { cout << a << endl; }
};

int main() {
    Point pt(2, 3);
    Point *p = &pt;
    
    void (Point::*pf1)() const;
    pf1 = &Point::Print;

    void (Point::*pf2)(int);
    pf2 = &Point::print_int;

    pt.Print();
    pt.print_int(10);
    cout << endl;

    (pt.*pf1)();
    (pt.*pf2)(10);
    cout << endl;

    return 0;
}
