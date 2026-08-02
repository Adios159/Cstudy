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

int N, M, dp[2009][2009];
string S, T;

int main() {
	// 입력
	cin >> S; N = S.size();
	cin >> T; M = T.size();

	// 동적 계획 알고리즘
	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i >= 1 && j >= 1 && S[i - 1] == T[j - 1]) {
				dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1 });
			}
			else if (i >= 1 && j >= 1) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else if (i >= 1) {
				dp[i][j] = dp[i - 1][j];
			}
			else if (j >= 1) {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	// 출력
	cout << dp[N][M] << endl;
	return 0;
}