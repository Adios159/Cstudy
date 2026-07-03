#include <iostream>
using namespace std;

int main() {
    int temp[100001];
    int day, minTemp, maxTemp, cnt = 0;
    cin >> day >> minTemp >> maxTemp;

    for(int i = 0; i < day; i++) {
        cin >> temp[i];
    }

    for(int i = 0; i < day; i++) {
        if(temp[i] >= minTemp && temp[i] <= maxTemp) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}