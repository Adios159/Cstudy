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

int H, W, Q;
int X[1509][1509], Z[1509][1509];
int A[100009], B[100009], C[100009], D[100009];

int main() {
    fastio;

    cin >> H >> W;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> X[i][j];
        }
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for(int i = 1; i <= H; i++) {
        for(int j = 0; j <= W; j++) {
            Z[i][j] = 0;
        }
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            Z[i][j] = Z[i][j - 1] + X[i][j];
        }
    }

    for(int j = 1; j <= W; j++) {
        for(int i = 1; i <= H; i++) {
            Z[i][j] = Z[i - 1][j] + Z[i][j];
        }
    }
    
    for(int i = 1; i <= Q; i++){
        cout << Z[C[i]][D[i]] + Z[A[i] - 1][B[i] - 1] - Z[A[i] - 1][D[i]] - Z[C[i]][B[i] - 1] << endl;
    }
    return 0;
}