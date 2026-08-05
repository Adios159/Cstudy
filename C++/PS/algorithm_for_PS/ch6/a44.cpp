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

int N, Q, State = 1;
int E[200009];

int main() {
	// 입력 → 배열 준비
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) E[i] = i;

	// 쿼리 처리
	for (int i = 1; i <= Q; i++) {
		int Type, x, y; cin >> Type;

		// [1] 변경 조작
		if (Type == 1) {
			cin >> x >> y;
			if (State == 1) E[x] = y;
			if (State == 2) E[N + 1 - x] = y;
		}

		// [2] 반전 조작
		if (Type == 2) {
			if (State == 1) State = 2;
			else State = 1;
		}

		// [3] 취득 조작
		if (Type == 3) {
			cin >> x;
			if (State == 1) cout << E[x] << endl;
			if (State == 2) cout << E[N + 1 - x] << endl;
		}
	}
	return 0;
}