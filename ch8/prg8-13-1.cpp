#include <iostream>
using namespace std;

int main() {
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};
    int arr2[4][3];
    for(int i = 0; i < 3; i++) {
        cout << endl;
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << "  ";
        }
    }

    cout << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            arr2[j][i] = arr[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        cout << endl;
        for(int j = 0; j < 3; j++) {
            cout << arr2[i][j] << " ";
        }
    }

    return 0;
}