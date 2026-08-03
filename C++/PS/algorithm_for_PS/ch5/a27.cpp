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

int GCD(int A, int B) {
	while (A >= 1 && B >= 1) {
		if (A >= B) {
			A = (A % B); // A의 값을 변경하는 경우
		}
		else {
			B = (B % A); // B의 값을 변경하는 경우
		}
	}
	if (A != 0) return A;
	return B;
}

int main() {
	int A, B;
	cin >> A >> B;
	cout << GCD(A, B) << endl;
	return 0;
}