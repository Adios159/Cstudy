#include <iostream>
#include <vector>
using namespace std;

int main() {
    int exercise, day, hStand;
    long long possiDay = 0;
    cin >> exercise >> day >> hStand;
    vector<int> exerciseArr(exercise);

    for(int i = 0; i < exercise; i++) {
        cin >> exerciseArr[i];
    }

    for(int j = 0; j < exercise; j++) {
        possiDay += exerciseArr[j] / hStand;
    }

    if(possiDay >= day) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}