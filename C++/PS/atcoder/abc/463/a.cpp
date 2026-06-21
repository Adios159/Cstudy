#include <iostream>
using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    if(X * 9 == Y * 16) {
        cout << "Yes" << endl;
    }
    else 
        cout << "No" << endl;
    return 0;
    }