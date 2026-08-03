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

long long H, W;
char c[39][39];
long long dp[39][39];

int main() {
	// 입력
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	// 동적 계획 알고리즘
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = 0;
				if (i >= 2 && c[i - 1][j] == '.') dp[i][j] += dp[i - 1][j];
				if (j >= 2 && c[i][j - 1] == '.') dp[i][j] += dp[i][j - 1];
			}
		}
	}

	// 출력
	cout << dp[H][W] << endl;
	return 0;
}