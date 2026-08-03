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

int N, A[100009], B[100009], dp[100009];

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) cin >> A[i];
	for (int i = 1; i <= N - 1; i++) cin >> B[i];

	dp[1] = 0;
	for (int i = 2; i <= N; i++) dp[i] = -1000000000;

	for (int i = 1; i <= N - 1; i++) {
		dp[A[i]] = max(dp[A[i]], dp[i] + 100);
		dp[B[i]] = max(dp[B[i]], dp[i] + 150);
	}
	cout << dp[N] << endl;
	return 0;
}