#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    int arr[100];
    int sum = 0, devi = 0, avg = 0;
    srand(time(0));
    
    for(int i = 0; i < 100; i++) {
        arr[i] = 100 + rand() % 101;
        sum += arr[i];
        cout << arr[i] << ' ';
    }

    avg = sum / 100;
    cout << endl;
    for(int i = 0; i < 100; i++) {
        devi += (arr[i] - avg) * (arr[i] - avg);
    }

    devi = sqrt((double)devi / 100);
    cout << devi << endl;

    return 0;
}