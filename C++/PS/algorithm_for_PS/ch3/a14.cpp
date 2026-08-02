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

int N, K, A[1009], B[1009], C[1009], D[1009];
int P[1000009], Q[1000009];

int main() {
	// 입력
	cin >> N >> K;
	for (int x = 1; x <= N; x++) cin >> A[x];
	for (int y = 1; y <= N; y++) cin >> B[y];
	for (int z = 1; z <= N; z++) cin >> C[z];
	for (int w = 1; w <= N; w++) cin >> D[w];

	// 배열 P를 작성
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) P[(x - 1) * N + y] = A[x] + B[y];
	}

	// 배열 Q를 작성
	for (int z = 1; z <= N; z++) {
		for (int w = 1; w <= N; w++) Q[(z - 1) * N + w] = C[z] + D[w];
	}
	// 배열 Q를 오름차순으로 정렬
	sort(Q + 1, Q + (N * N) + 1);

	// 바이너리 서치
	for (int i = 1; i <= N * N; i++) {
		int pos1 = lower_bound(Q + 1, Q + (N * N) + 1, K - P[i]) - Q;
		if (pos1 <= N * N && Q[pos1] == K - P[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	// 발견하지 못한 경우
	cout << "No" << endl;
	return 0;
}