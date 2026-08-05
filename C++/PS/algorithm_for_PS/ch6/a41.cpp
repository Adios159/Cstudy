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
	int N; char S[200009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];

	// 답을 구한다
	bool Answer = false;
	for (int i = 1; i <= N - 2; i++) {
		if (S[i] == 'R' && S[i + 1] == 'R' && S[i + 2] == 'R') Answer = true;
		if (S[i] == 'B' && S[i + 1] == 'B' && S[i + 2] == 'B') Answer = true;
	}

	// 출력
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}