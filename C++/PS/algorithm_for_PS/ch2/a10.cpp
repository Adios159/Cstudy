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

int N, A[100009], P[100009], Q[100009];
int D, L[100009], R[100009];

int main() {
    fastio;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> D;
	for (int d = 1; d <= D; d++) cin >> L[d] >> R[d];

	P[1] = A[1];
	for (int i = 2; i <= N; i++) P[i] = max(P[i - 1], A[i]);

	Q[N] = A[N];
	for (int i = N - 1; i >= 1; i--) Q[i] = max(Q[i + 1], A[i]);

	for (int d = 1; d <= D; d++) {
		cout << max(P[L[d] - 1], Q[R[d] + 1]) << endl;
	}
	return 0;
}