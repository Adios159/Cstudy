#include <iostream>
using namespace std;

int main() {
    long long check;
    long long sPoint[1000001], hPoint[1000001];
    cin >> check;

    for(int i = 0; i < check; i++) cin >> sPoint[i];
    for(int j = 0; j < check - 1; j++) cin >> hPoint[j];

    long long cur = sPoint[0];
    long long satisMax = cur;

    for(int i = 1; i < check; i++) {
        cur += sPoint[i] - hPoint[i-1];
        if(cur > satisMax) satisMax = cur;
    }

    cout << satisMax << endl;
    return 0;
}