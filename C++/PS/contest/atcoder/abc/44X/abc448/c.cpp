#include <bits/stdc++.h>
using namespace std;

// ---------- 타입 별칭 ----------
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pll> vpll;

// ---------- 매크로 ----------
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// ---------- 상수 ----------
const int INF = 1e9;
const ll LLINF = 4e18;
const int MOD = 1e9 + 7;

int main() {
    fastio;
    int N, Q, A, K, B;
    cin >> N >> Q;
    vpll ball;
    int i = 1;
    while(N--) {
        cin >> A;
        ball.push_back(make_pair(A, i));
        i++;
    }
    vpll copy_ball = ball;
    sort(all(copy_ball));

    while(Q--) {
        cin >> K;
        vector<int> picked(K);
        for (auto &b : picked) cin >> b;

        int idx = 0;
        while (true) {
            int candNum = copy_ball[idx].second;   // 후보 공의 "번호"
            bool removed = false;
            for (int b : picked) {
                if (b == candNum) {
                    removed = true;
                    break;
                }
            }
            if (removed) {
                idx++;              // 이 후보는 지워졌으니 다음으로
            } else {
                cout << copy_ball[idx].first << '\n';  // 안 지워졌으면 이게 정답
                break;
            }
        }
    }
    return 0;
}