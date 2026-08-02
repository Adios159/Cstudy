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

int N, S, A[69];
bool dp[69][10009];

int main() {
	// 입력
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 동적 계획 알고리즘 (i = 0)
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;

	// 동적 계획 알고리즘 (i >= 1)
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (j < A[i]) {
				if (dp[i - 1][j] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
			if (j >= A[i]) {
				if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}

	// 출력
	if (dp[N][S] == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}