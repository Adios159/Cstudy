#include <iostream>
using namespace std;

int main() {
    int P, Q, X, Y;
    cin >> P >> Q;
    cin >> X >> Y;
    if((X >= P && X <= P + 99) && (Y >= Q && Y <= Q + 99)) {
        cout << "Yes" << endl;
    } 
    else {
        cout << "No" << endl;
    }
    return 0;
}