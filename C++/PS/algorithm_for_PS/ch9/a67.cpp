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

class UnionFind {
public:
	int par[100009];
	int siz[100009];

	// N 노드의 Union-Find를 작성
	void init(int N) {
		for (int i = 1; i <= N; i++) par[i] = -1; // 최초에는 부모가 없다
		for (int i = 1; i <= N; i++) siz[i] = 1; // 최초에는 그룹의 노드 수가 1
	}

	// 노드 x의 루트를 반환하는 함수
	int root(int x) {
		while (true) {
			if (par[x] == -1) break; // 1개 앞(부모)이 없으면 여기가 루트
			x = par[x]; // 1 개 앞(부모)으로 진행한다
		}
		return x;
	}

	// 요소 u와 v를 통합하는 함수
	void unite(int u, int v) {
		int RootU = root(u);
		int RootV = root(v);
		if (RootU == RootV) return; // u와 v가 같은 그룹일 때는 처리를 수행하지 않는다
		if (siz[RootU] < siz[RootV]) {
			par[RootU] = RootV;
			siz[RootV] = siz[RootU] + siz[RootV];
		}
		else {
			par[RootV] = RootU;
			siz[RootU] = siz[RootU] + siz[RootV];
		}
	}

	//요소 u와 v가 같은 그룹인지 반환하는 함수
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

	// 에지를 길이의 오름차순으로 정렬한다
	vector<pair<int, int>> EdgeList;
	for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
	sort(EdgeList.begin(), EdgeList.end());

	// 최소 전역 트리를 구한다
	int Answer = 0; UF.init(N);
	for (int i = 0; i < EdgeList.size(); i++) {
		int idx = EdgeList[i].second;
		if (UF.same(A[idx], B[idx]) == false) {
			UF.unite(A[idx], B[idx]);
			Answer += C[idx];
		}
	}
	cout << Answer << endl;
	return 0;
}