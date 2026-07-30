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
    ll N, K, A, B, num = 1;
    vpll player;
    vl permitted;
    cin >> N >> K;
    while(N--) {
        cin >> A >> B;
        player.push_back(make_pair(-(A + B), num));
        num++;
    }
    sort(all(player));
    ll idx = 0;
    while(K--) {
        permitted.push_back(player[idx].second);
        idx++;
    }
    sort(permitted.begin(), permitted.end());
    for(int i = 0; i < permitted.size(); i++) {
        cout << permitted[i] << ' ';
    }
    cout << '\n';
    return 0;
}