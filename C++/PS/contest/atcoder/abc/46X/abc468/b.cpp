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
    int N, D, cnt = 0;
    string S;
    cin >> N >> D;
    cin >> S;
    vi seq;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'G') {
            seq.push_back(i);
        }
    }
    vector<bool> watch(N);
    for(int i = 0; i < seq.size(); i++) {
        int min = seq[i] - D > 0 ? seq[i] - D : 0;
        int max = seq[i] + D < N - 1 ? seq[i] + D : N - 1;
        for(int j = min; j <= max; j++) {
            watch[j] = true;
        }
    }
    
    for(int i = 0; i < watch.size(); i++) {
        if(watch[i] == false) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}