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
const int MOD = 998244353;
const double PI = 3.14159265358979;

int main() {
    fastio;
    ll N, M, A, B;
    ll num, total = 0;
    cin >> N >> M;
    vl Anum;
    vl Bnum;
    vl prefix(N + 1);
    for(int i = 0; i < N; i++) {
        cin >> num;
        Anum.push_back(num);
    }
    for(int i = 0; i < M; i++) {
        cin >> num;
        Bnum.push_back(num);
    }
    sort(Anum.begin(), Anum.end());
    prefix[0] = 0;
    for(int i = 1; i <= Anum.size(); i++) {
        prefix[i] = prefix[i - 1] + Anum[i - 1];
    }
    for(int i = 0; i < Bnum.size(); i++) {
        int k = lower_bound(Anum.begin(), Anum.end(), Bnum[i]) - Anum.begin();
        ll s = prefix[k];
        total += ((Bnum[i] * k - s) + ((prefix[prefix.size() - 1] - s) - Bnum[i] * (N - k))) % MOD;
    }
    cout << total % MOD<< '\n';
    return 0;
}