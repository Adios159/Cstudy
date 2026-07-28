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
    int N;
    cin >> N;
    
    ll ab, bc, ac;
    ll C[102][102];
    for (int i = 1; i <= N-1; i++) {
        for (int j = i+1; j <= N; j++) {
            cin >> C[i][j];
        }
    }

    for (int a = 1; a <= N; a++) {
        for (int b = a+1; b <= N; b++) {
            for (int c = b+1; c <= N; c++) {
                ab = C[a][b];
                bc = C[b][c];
                ac = C[a][c];
                if(ab + bc < ac) {
                    cout << "Yes\n";
                    return 0; 
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}