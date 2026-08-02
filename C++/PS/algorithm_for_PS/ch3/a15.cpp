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
	int N, A[100009], B[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	vector<int> T;
	for (int i = 1; i <= N; i++) T.push_back(A[i]);
	sort(T.begin(), T.end());

	T.erase(unique(T.begin(), T.end()), T.end());

	for (int i = 1; i <= N; i++) {
		B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
		B[i] += 1;
	}

	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << B[i];
	}
	cout << endl;
	return 0;
}