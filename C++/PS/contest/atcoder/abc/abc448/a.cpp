/*
 * PS(Problem Solving) 템플릿
 * - bits/stdc++.h 대신 필요한 헤더만 개별 include
 * - AtCoder / Codeforces 등에서 그대로 복붙해서 쓰는 용도
 */

#include <bits/stdc++.h>
using namespace std;

// ---------- 타입 별칭 ----------
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

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
    int N, X, A;
    cin >> N >> X;
    vi num;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A < X) {
            X = A;
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}