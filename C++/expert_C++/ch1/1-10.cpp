#include <iostream>
using namespace std;

int main() {
    struct point {double mx, my, mz;};
    point point_t;
    point_t.mx = 1.0;
    point_t.my = 2.0;
    point_t.mz = 3.0;
    auto [x, y, z] {point_t};

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    return 0;
}