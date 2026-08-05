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

int N, M, A[100009], B[100009];
int dist[100009];
vector<int> G[100009];
queue<int> Q;

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 너비 우선 탐색(dist[i]=?가 아니라 dist[i]=-1로 초기화하는 것에 주의)
	for (int i = 1; i <= N; i++) dist[i] = -1;
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}

	// 출력
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}