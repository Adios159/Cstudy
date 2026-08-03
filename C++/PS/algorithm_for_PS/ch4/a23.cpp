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

int N, M, A[109][19];
int dp[109][1024];

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}

	// 배열 초기화
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) dp[i][j] = 1'000'000'000;
	}

	// 동적 계획 알고리즘
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) {
			// already[k] = 1일 때, 물품 k는 이미 무료 상태다
			int already[19];
			for (int k = 1; k <= N; k++) {
				if ((j / (1 << (k - 1))) % 2 == 0) already[k] = 0;
				else already[k] = 1;
			}

			// 쿠폰 i를 선택한 경우의 정수 표현 v를 계산한다
			int v = 0;
			for (int k = 1; k <= N; k++) {
				if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
			}

			// 이동을 수행한다
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][v] = min(dp[i][v], dp[i - 1][j] + 1);
		}
	}

	// 출력(모두 선택한 경우의 정수 표현은 2^N-1)
	if (dp[M][(1 << N) - 1] == 1'000'000'000) cout << "-1" << endl;
	else cout << dp[M][(1 << N) - 1] << endl;
	return 0;
}