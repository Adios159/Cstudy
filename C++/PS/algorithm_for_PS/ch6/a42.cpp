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

int N, K;
int A[309], B[309];

// 정수의 쌍(a, b)가 결정되었을 때 참가 가능한 학생 수를 반환하는 함수
int GetScore(int a, int b) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (a <= A[i] && A[i] <= a + K && b <= B[i] && B[i] <= b + K) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	// (a, b)쌍을 완전 탐색
	int Answer = 0;
	for (int a = 1; a <= 100; a++) {
		for (int b = 1; b <= 100; b++) {
			int Score = GetScore(a, b);
			Answer = max(Answer, Score);
		}
	}

	// 출력
	cout << Answer << endl;
	return 0;
}