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

int N, A[100009], B[100009], dp[100009];
vector<int> Answer;

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];

	dp[1] = 0;
	dp[2] = A[2];
	for (int i = 3; i <= N; i++) dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);

	int Place = N;
	while (true) {
		Answer.push_back(Place);
		if (Place == 1) break;

		if (dp[Place - 1] + A[Place] == dp[Place]) Place = Place - 1;
		else Place = Place - 2;
	}

	reverse(Answer.begin(), Answer.end());
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i] << ' ';
	}
	cout << endl;
	return 0;
}