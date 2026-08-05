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
	// 입력
	int N; char C, A[200009];
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 점수 계산
	int score = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 'W') score += 0;
		if (A[i] == 'B') score += 1;
		if (A[i] == 'R') score += 2;
	}
	// 출력
	if (score % 3 == 0 && C == 'W') cout << "Yes" << endl;
	else if (score % 3 == 1 && C == 'B') cout << "Yes" << endl;
	else if (score % 3 == 2 && C == 'R') cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}