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
    fastio;
    int t, n, k;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s;
        vi count1(k);
        bool all_even = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                count1[(i % k)]++;
            }
        }
        for(int i = 0;  i < count1.size(); i++) {
            if(count1[i] % 2 == 1) {
                all_even = false;
                break;
            }
        }
        if(all_even == true) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}