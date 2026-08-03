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
	long long N, A[100009]; char T[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> A[i];

	// 출력(Answer는 현재 칠판의 수)
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (T[i] == '+') Answer += A[i];
		if (T[i] == '-') Answer -= A[i];
		if (T[i] == '*') Answer *= A[i];

		// 뺄셈의 답이 0 미만이 된 경우
		if (Answer < 0) Answer += 10000;

		// 여기에서 나머지를 구한다!
		Answer %= 10000;
		cout << Answer << endl;
	}
	return 0;
}