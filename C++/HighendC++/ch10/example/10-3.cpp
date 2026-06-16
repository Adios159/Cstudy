#include <iostream>
using namespace std;

template <class T>
T add(T data[], int size) {
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    double y[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << add(x, 5) << endl;
    cout << add(y, 5) << endl;

    return 0;
}