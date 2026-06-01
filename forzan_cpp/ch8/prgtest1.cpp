#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[10][10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 100 + rand() % 101;
            cout << arr[i][j] << ' ';
        }
        
    }

    return 0;
    
}