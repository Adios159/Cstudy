#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    long long G;
    long long totalT = 0;
    cin >> N >> K >> G;

    vector<long long> d(N), t(N);
    for(int i = 0; i < N; i++) {
        cin >> d[i] >> t[i];
    }

    // 첫 윈도우 합
    long long windowSum = 0;
    for(int i = 0; i < K; i++) {
        windowSum += t[i];
    }

    long long maxSkip = windowSum;

    // 슬라이딩
    for(int i = K; i < N; i++) {
        windowSum += t[i] - t[i - K];
        if(windowSum > maxSkip) 
            maxSkip = windowSum;
    }
    for(int i = 0; i < N; i++) {
        totalT += t[i];
    }

    cout << G + totalT - maxSkip << endl;
    return 0;
}