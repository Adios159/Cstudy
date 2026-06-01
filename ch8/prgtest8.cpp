#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[6][6] {{1, 2, 3, 4, 5, 6},
                   {1, 2, 3, 4, 5, 6},
                   {1, 2, 3, 4, 5, 6},
                   {1, 2, 3, 4, 5, 6},
                   {1, 2, 3, 4, 5, 6},
                   {1, 2, 3, 4, 5, 6}};
    int arr1[6], arr2[6];

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < 6; i++) {
        arr1[i] = arr[i][i];
        cout << arr1[i] << ' ';
    }
    cout << endl;

    for(int j = 0; j < 6; j++) {
        arr2[j] = arr[j][5-j];
        cout << arr2[j] << ' ';
    }
    cout << endl;

    return 0;
}