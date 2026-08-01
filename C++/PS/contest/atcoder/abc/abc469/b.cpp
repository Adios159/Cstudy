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
    int N, cnt=0;
    string S;
    cin >> N;
    cin >> S;
    if(N == 1 && S == "x") {
        if(S == "x") {
            cout << 1 << endl;
            return 0;
        }
        else {
            cout << 0 << endl;
            return 0;
        }
    } 
    if(S[0] == 'x' && S[1] == 'x')
        cnt++;
    for(int i = 1; i < S.size() - 1; i++) {
        if(S[i] == 'o') {
            continue;
        }
        else {
            if(S[i - 1] == 'x' && S[i + 1] == 'x') {
                cnt++;
            }
        }
    }
    if(S[S.size() - 1] == 'x' && S[S.size() - 2] == 'x')
        cnt++;
    cout << cnt << endl;
    return 0;
}