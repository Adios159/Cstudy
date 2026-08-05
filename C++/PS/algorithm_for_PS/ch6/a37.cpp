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

long long N, M, B;
long long A[200009], C[200009];

int main() {
	// 입력
	cin >> N >> M >> B;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= M; j++) cin >> C[j];

	// 답 계산
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += A[i] * M;
	Answer += B * N * M;
	for (int j = 1; j <= M; j++) Answer += C[j] * N;

	// 출력
	cout << Answer << endl;
	return 0;
}