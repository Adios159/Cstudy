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

int D, N;
int L[10009], R[10009], H[10009], LIM[10009];

int main() {
	// 입력
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];

	// 배열 초기화(1일은 24시간)
	for (int i = 1; i <= D; i++) LIM[i] = 24;

	// 상한 값을 구한다
	for (int i = 1; i <= N; i++) {
		for (int j = L[i]; j <= R[i]; j++) LIM[j] = min(LIM[j], H[i]);
	}

	// 답을 출력
	int Answer = 0;
	for (int i = 1; i <= D; i++) Answer += LIM[i];
	cout << Answer << endl;
	return 0;
}