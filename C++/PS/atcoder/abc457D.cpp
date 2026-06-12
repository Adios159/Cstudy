#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long>& A, long long mid, long long K) {
    long long result = 0;
    for (long long i = 1; i <= (long long)A.size(); i++) {
        if (A[i-1] < mid) {
            result += (mid - A[i-1] + (long long)i - 1) / (long long)i;
        }
        if (result > K || result < 0) return false;
        if (result > K) return false;
    }
    return result <= K;
}

int main() {
    long long N, K;
    cin >> N >> K;

    vector<long long> arr(N);
    

        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    long long lo = 1;
    long long hi = 2e18;
    long long ans = lo;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(arr, mid, K)) {
            ans = mid;      // 가능하면 답 갱신, 더 큰 값 시도
            lo = mid + 1;
        } else {
            hi = mid - 1;   // 불가능하면 줄임
        }
    }

    
    cout << ans << endl;    
    return 0;
}