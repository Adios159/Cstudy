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
    short M, D;
    cin >> M >> D;
    switch(M) {
        case 1:
            if(D == 7) {
                cout << "Yes\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
        case 3:
            if(D == 3) {
                cout << "Yes\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
        case 5:
            if(D == 5) {
                cout << "Yes\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
        case 7:
            if(D == 7) {
                cout << "Yes\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
        case 9:
            if(D == 9) {
                cout << "Yes\n";
                return 0;
            }
            else {
                cout << "No\n";
                return 0;
            }
        default:
            cout << "No\n";
            return 0;
    }
}