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
typedef vector<vi> vvi;
typedef vector<vl> vvl;

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
    ll N;
    string S;
    cin >> N;
    cin >> S;
    vi xpos;
    vector<int> po(N+1, 0);
    for(ll i = 1; i <= N; i++) {
        po[i] = po[i-1] + (S[i-1] == 'o' ? 1 : 0);
    }
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'x') 
            xpos.push_back(i + 1);
    }
    for(int k = 1; k <= N; k++) {
        ll target = k - 1;
        if(target < xpos.size()) {
            cout << xpos[target] << '\n';
        }
        else {
            cout << N << '\n';
        }
    }
    return 0;
}