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
	int N, A[200009]; long long cnt[109], Answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 개수를 센다
	for (int i = 1; i <= 100; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;

	// 답을 구한다
	// nC3 = n * (n-1) * (n-2) / 6 을 사용한다
	for (int i = 1; i <= 100; i++) {
		Answer += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	}
	cout << Answer << endl;
	return 0;
}