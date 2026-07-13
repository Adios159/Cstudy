#include <iostream>
using namespace std;

class Polygon {
    int size = 0;
    int *xList, *yList;
public:
    Polygon(int size) {
        this->size = size;
        xList = new int[size];
        yList = new int[size];
    }

    ~Polygon() {
        delete[] xList;
        delete[] yList;
    }

    void read() {
        cout << "put " << this->size << " points x, y" << endl;
        int xPos = 0, yPos = 0;
        for(int i = 0; i < size; i++) {
            cin >> xPos >> yPos;
            xList[i] = xPos;
            yList[i] = yPos;  // 수정: xPos → yPos
        }
    }

    bool get(int n, int *x, int *y) {
        if(n < 1 || n > size) {  // 수정: .size() → size 멤버 변수
            return false;
        }
        *x = xList[n - 1];
        *y = yList[n - 1];
        return true;
    }
};

int main() {
    Polygon poly(6);
    poly.read();
    int n = 3, x, y;
    bool res = poly.get(n, &x, &y);  // 수정
    if(res) cout << "x=" << x << ", y=" << y << endl;
    else    cout << "invalid index" << endl;
}