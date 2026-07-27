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
const double PI = 3.14159265358979;

int main() {
    fastio;
    int T, N, A;
    cin >> T;
    while(T--) {
        cin >> N;
        vl pile(N);
        for (auto &x : pile) cin >> x;

        ll S = 0;
        bool ok = true; 
        for (int k = 0; k < N; k++) {
            S += pile[k];

            ll threshold =  ((ll)k + 2) * ((ll)k + 1) / 2;

            if (S < threshold) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}