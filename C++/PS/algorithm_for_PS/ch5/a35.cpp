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

int N, A[2009];
int dp[2009][2009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 동적 계획 알고리즘 [ N번째 층 ]
	for (int j = 1; j <= N; j++) dp[N][j] = A[j];

	// 동적 계획 알고리즘 [ 1 ~ N-1번째 층 ]
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (i % 2 == 1) dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
			if (i % 2 == 0) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	// 출력
	cout << dp[1][1] << endl;
	return 0;
}