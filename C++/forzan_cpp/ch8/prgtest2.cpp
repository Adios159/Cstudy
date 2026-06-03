#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[10];
    srand(time(0));

    for(int i = 0; i < 10; i++) {
        arr[i] = 1 + rand() % 10;
        cout << arr[i] << ' ';
    }

    cout << endl;
    return 0;
}