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
    ll N, Q, X, Y, C;
    cin >> N >> Q;
    vl pos(N + 1);
    vl val(N + 1);
    bool print_pos = true;
    for(int i = 1; i < N + 1; i++) {
        cin >> val[i];
        pos[val[i]] = i;
    }
    while(Q--) {
        cin >> C;
        if(C == 2) {
            print_pos = !print_pos;
        }
        else {
            cin >> X >> Y;
            if(print_pos == true) {
                swap(val[X], val[Y]);
                swap(pos[val[X]], pos[val[Y]]);
            }
            else {
                swap(pos[X], pos[Y]);
                swap(val[pos[X]], val[pos[Y]]);
            }
        }
    }
    if(print_pos == false) {
        for(int i = 1; i < N + 1; i++) {
            cout << pos[i] << ' ';
        }
    }
    else {
        for(int i = 1; i < N + 1; i++) {
            cout << val[i] << ' ';
        }
    }
    return 0;
}