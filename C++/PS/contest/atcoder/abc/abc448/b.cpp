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
    int N, M, A, B, C;
    ll total = 0;
    cin >> N >> M;
    vi pepper;
    vpll use;
    for(int i = 0; i < M; i++) {
        cin >> C;
        pepper.push_back(C);
    }
    for(int i = 0; i < N; i++) {
        cin >> A >> B;
        use.push_back(make_pair(A, B));
    }

    sort(all(use));
    for(pair p : use) {
        if(p.second <= pepper[(p.first) - 1]) {
            total += p.second;
            pepper[(p.first) - 1] -= p.second;
        }
        else {
            if(pepper[(p.first) - 1] > 0) {
                total += pepper[(p.first) - 1];
                pepper[(p.first) - 1] = 0;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}