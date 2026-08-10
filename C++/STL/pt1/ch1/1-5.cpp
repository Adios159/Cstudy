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
    bool operator==(const Point &arg) {
        return x == arg.x && y == arg.y ? true : false;
    }
    bool operator!=(const Point &arg) {
        return x == arg.x && y == arg.y ? false : true;
    } 
};

int main() {
    Point p1(2, 3), p2(2, 3), p3(5, 5);
    cout << p1.operator==(p2) << endl;
    cout << p1.operator==(p3) << endl;
    cout << p1.operator!=(p2) << endl;
    cout << p1.operator!=(p3) << endl;

    return 0;
}