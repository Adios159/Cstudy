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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    int M;
    cin >> M;

    vector<string> S(M);
    for (int i = 0; i < M; ++i) {
        cin >> S[i];
    }

    vector<vector<bool>> valid(N, vector<bool>(26, false));

    for (const string& s : S) {
        int len = s.length();
        for (int i = 0; i < N; ++i) {
            if (A[i] == len) {
                valid[i][s[B[i] - 1] - 'a'] = true;
            }
        }
    }

    for (int j = 0; j < M; ++j) {
        if (S[j].length() != (size_t)N) {
            cout << "No\n";
            continue;
        }

        bool possible = true;
        for (int i = 0; i < N; ++i) {
            if (!valid[i][S[j][i] - 'a']) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}