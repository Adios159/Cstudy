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

int N, L[300009], R[300009];
vector<pair<int, int>> tmp; // 영화를 정렬하기 위한 임시 변수

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
		tmp.push_back(make_pair(R[i], L[i]));
	}

	// R의 오름차순으로 정렬
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= N; i++) {
		R[i] = tmp[i - 1].first;
		L[i] = tmp[i - 1].second;
	}

	// 종료 시각이 빠른 것부터 탐욕적으로 취해 간다(CurrentTime은 현재 시각)
	int CurrentTime = 0, Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= L[i]) {
			CurrentTime = R[i];
			Answer += 1;
		}
	}
	cout << Answer << endl;
	return 0;
}