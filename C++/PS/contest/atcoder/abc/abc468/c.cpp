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

ll power_10(int num) {
    ll temp = 1;
    for(int i = 0; i < num; i++) {
        temp *= 10;
    }
    return temp;
}

ll make_num(vi seq) {
   ll temp = 0;
   for(int i = 0; i < seq.size(); i++) {
        temp += seq[i] * power_10(seq.size() - 1 - i);
    } 
    return temp;
}

int main() {
    fastio;
    int N;
    cin >> N;
    vi seq(N), p(N), q(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> q[i];
    }
    seq = p;
    ll min = make_num(p);
    ll max = make_num(q);
    sort(seq.begin(), seq.end());
    vl per;
    do {
        per.push_back(make_num(seq));
    }while(next_permutation(seq.begin(), seq.end()));
    ll cnt = 0;
    cnt = lower_bound(per.begin(), per.end(), max) - upper_bound(per.begin(), per.end(), min);
    if (cnt < 0) cnt = 0;
    
    cout << cnt << '\n';
    return 0;
}