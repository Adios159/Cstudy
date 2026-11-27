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
    int operator[](int idx) const {
        if(idx == 0)
            return x;
        else if(idx == 1)
            return y;
        else 
            throw "No index";
    }
};

int main() {
    point p1(2, 3);
    p1.print();

    cout << p1[0] << ' ' << p1[1] << endl;
    return 0;
}