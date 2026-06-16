#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b) {
    if(a > b) return a;
    else return b;
}

int main() {
    cout << bigger(20, 50) << endl;
    cout << bigger('a', 'z') << endl;

    return 0;
}