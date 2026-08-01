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

ll N, K;
ll A[100009];

bool check(ll x) {
    ll sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += x / A[i];
    }
    if(sum >= K) return true;
    return false;
}

int main() {
    fastio;
    ll num;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    ll left = 1, right = 1'000'000'000;
    while(left < right) {
        ll mid = (left + right) / 2;
        bool ans = check(mid);
        if(ans == false) left = mid + 1;
        if(ans == true) right = mid;
    }
    cout << left << '\n';
    return 0;
}