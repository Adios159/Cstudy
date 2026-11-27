#include <iostream>
#include <algorithm>
using namespace std;

struct func1
{
    void operator() (int n) {
        cout << n <<  endl;
    }
};

struct func2 {
    void operator() (int n) {
        cout << n * n << endl;
    }
};

struct func3 {
    void operator() (int n) {
        cout << "num: " << n << endl;
    }
};
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for_each(arr, arr + 5, func1());
    cout << endl;

    for_each(arr, arr + 5, func2());
    cout << endl;

    for_each(arr, arr + 5, func3());
    cout << endl;

    return 0; 
}