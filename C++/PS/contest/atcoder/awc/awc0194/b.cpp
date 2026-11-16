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
typedef string str;
typedef vector<bool> vb;

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
    short N, M, max = 0, row = 1;
    char flower[11][11];

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> flower[i][j];
        }
    }

    for(int j = 1; j <= M; j++) {
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(flower[i][j] == 'F') {
                cnt++;
            }
        }
        if(max < cnt) {
            max = cnt;
            row = j;
        }
    }
    cout << row << endl;
    return 0;
}