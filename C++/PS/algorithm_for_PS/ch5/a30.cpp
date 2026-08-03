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

long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m; // 'a의 2i 제곱'이 곱해졌을 때
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b를 m으로 나눈 나머지를 반환하는 함수
// 함수 Power는 5.4절을 참조
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

int main() {
	// 입력
	const long long M = 1000000007;
	long long n, r;
	cin >> n >> r;

	// 순서 1: 분자 a를 구한다
	long long a = 1;
	for (int i = 1; i <= n; i++) a = (a * i) % M;

	// 순서 2: 분모 b를 구한다
	long long b = 1;
	for (int i = 1; i <= r; i++) b = (b * i) % M;
	for (int i = 1; i <= n - r; i++) b = (b * i) % M;

	// 순서 3: 답을 구한다
	cout << Division(a, b, M) << endl;
	return 0;
}