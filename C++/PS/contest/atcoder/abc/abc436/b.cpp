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
    int board[110][110] = {0};
    board[0][(N - 1) / 2] = 1;
    int r = 0;
    int c = (N - 1) / 2;
    for(int i = 2; i <= N * N; i++) {
        if(board[((r - 1) % N + N)% N][((c + 1) % N +N ) % N] == 0) {
            board[((r-1) % N + N)% N][((c + 1) % N +N ) % N] = i;
            r = ((r-1) % N + N) % N;
            c = ((c + 1) % N +N ) % N;
        }
        else {
            board[((r + 1) % N + N)%N][(c % N +N ) %N ] = i;
            r = ((r + 1) % N + N) % N;
            c = (c % N +N ) % N;
        }
    }
    for(int i = 0;  i < N; i++) {
        for(int j = 0;  j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}