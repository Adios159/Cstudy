#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, K, X;
    long long A;
    cin >> N >> K >> X;
    vector<long long> sake;
    for(int i = 0;  i < N; i++) {
        cin >> A;
        sake.push_back(A);
    }
    long long sum = 0;
    long long answer = -1;
    sort(sake.rbegin(), sake.rend());
    for(int m = 1; m <= N; m++) {
        if (m > N - K) {
            // 여기서 sum에 뭘 더해야 할까? (m번째, 1-indexed 원소)
            sum += sake[m - 1];
        }
        if (sum >= X) {
            answer = m;
            break;
        }
    }
    cout << answer << endl;
}