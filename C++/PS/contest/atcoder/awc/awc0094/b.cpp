#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long A, N, K, sum = 0, last = 0;;
    cin >> N >> K;
    vector<long> temperature;
    vector<long> sums;
    for(int i = 0; i < N; i++) {
        cin >> A;
        temperature.push_back(A);
    }
    for(int i = 0; i < K; i++) {
        sum += temperature[i];
    }
    sums.push_back(sum);
    last = temperature[0];
    for(int i = K; i < temperature.size(); i++) {
        sum -= last;
        sum += temperature[i];
        sums.push_back(sum);
        last = temperature[i - K + 1];
    }
    sort(sums.rbegin(), sums.rend());
    cout << sums[0] - sums[sums.size() - 1] << endl;
    return 0;
}