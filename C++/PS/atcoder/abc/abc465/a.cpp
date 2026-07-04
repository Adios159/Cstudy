#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(a > (int)(b * 2 / 3)) {
        cout << "Yes" << endl;
    }
    else  
        cout << "No" << endl;
    return 0;
}