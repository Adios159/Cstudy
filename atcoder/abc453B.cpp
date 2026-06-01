#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int time, differ, temp = 0;    
    cin >> time >> differ;
    int value[101];
    for(int i = 0; i <= time; i++) {
        cin >> value[i]; 
    }

    temp = value[0];
    cout << 0 << ' ' << temp << endl;
    for(int j = 1; j <= time; j++) {
        if(abs(temp - value[j]) >= differ) {
            cout << j << ' ' << value[j] << endl;
            temp = value[j];
        }
    }

    return 0;
}