#include <iostream>
using namespace std;

int main() {
    int a, b, c, num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> a >> b >> c;
        if(a < b && b < c) 
            cout << "STAIR" << endl;
        else if(a < b && b > c)
            cout << "PEAK" << endl;
        else
            cout << "NONE" << endl;
    }

    return 0;
}