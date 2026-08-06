#include <iostream>
using namespace std;

int main() {
    int x, y, a, b, l, r;
    int total = 0;
    cin >> x >> y >> l >> r >> a >> b;
    for(int i = a; i < b; i++) {
        if(i >= l && i < r) {
            total += x;
        }
        else {
            total += y;
        }
    }
    cout << total << endl;
    return 0;
}