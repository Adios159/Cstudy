#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, pivotMin, min, minmin = 100000000000001;
    cin >> N >> pivotMin;
    if(pivotMin == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        long long temp = 0;
        cin >> min;
        // temp = pivotMin / min;
        // if(temp == 0) {
        //     temp = min;
        // }
        // else if(pivotMin % min == 0) {
        //     temp = min * (pivotMin / min);
        // }
        // else {
        //     temp = min * ((pivotMin / min) + 1);
        // }
        temp = ((pivotMin + min - 1) / min) * min;

        if(minmin > temp) {
            minmin = temp;
        }
    }
    cout << minmin << endl;
    return 0;
}