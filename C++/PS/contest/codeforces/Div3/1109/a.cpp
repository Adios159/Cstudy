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
    int N, L;
    int cnt = 0, max_sec = 0, sec = 0; 
    string S;
    cin >> N;
    while(N--) {
        cin >> L;
        cin >> S;
        cnt = 0, max_sec = 0, sec = 0; 
        for(int i = 0; i <  S.size(); i++) {
            if(S[i] == '#') {
                cnt++;
            }
            else {
                sec = (cnt + 1) / 2;
                if(max_sec < sec) {
                    max_sec = sec;
                }
                cnt = 0;
            }
            sec = (cnt + 1) / 2;
            if(max_sec < sec) {
                max_sec = sec;
            }
        }
        cout << max_sec << '\n';
    }
    return 0;
}