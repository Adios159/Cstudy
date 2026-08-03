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

int N, A, B;
bool dp[100009];

int main() {
	// 입력
	cin >> N >> A >> B;

	// 승자를 계산한다
	for (int i = 0; i <= N; i++) {
		if (i >= A && dp[i - A] == false) dp[i] = true; // 승리 상태
		else if (i >= B && dp[i - B] == false) dp[i] = true; // 승리 상태
		else dp[i] = false; // 패배 상태
	}

	// 출력
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}