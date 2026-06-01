#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, offset, idx;
    long long K, amount = 0, totalSum = 0;
    cin >> N >> K;

    vector<vector<int>> arr(N);
    vector<long long> C(N);

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        arr[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        long long blockSize = (long long)arr[i].size() * C[i];  
        if (totalSum + blockSize >= K) {
            long long offset = K - totalSum;
            int idx = (offset - 1) % arr[i].size();
            cout << arr[i][idx];
            break;
        }
        totalSum += blockSize;  
    }

    return 0;
}