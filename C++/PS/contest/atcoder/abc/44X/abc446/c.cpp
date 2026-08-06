#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve() {
    int N;
    long long D;
    cin >> N >> D;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    deque<pair<int, long long>> dq;

    for (int i = 1; i <= N; ++i) {
        dq.push_back({i, A[i - 1]});

        long long needed = B[i - 1];
        while (needed > 0 && !dq.empty()) {
            if (dq.front().second <= needed) {
                needed -= dq.front().second;
                dq.pop_front();
            } else {
                dq.front().second -= needed;
                needed = 0;
            }
        }

        long long cutoff = i - D;
        while (!dq.empty() && dq.front().first <= cutoff) {
            dq.pop_front();
        }
    }

    long long remaining = 0;
    for (const auto& batch : dq) {
        remaining += batch.second;
    }

    cout << remaining << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}