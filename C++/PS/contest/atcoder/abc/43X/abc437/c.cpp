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
    ll T, N, W, P;
    cin >> T;
    while(T--) {
        vpll horse;
        ll Wtotal = 0, Ptotal = 0;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> W >> P;
            horse.push_back(make_pair(W + P, P));   
        }

        sort(horse.begin(), horse.end());
        for(int i = 0; i < horse.size(); i++) {
            Ptotal += horse[i].second;
        }

        for(int i = 0; i < horse.size(); i++) {
            Ptotal -= horse[i].second;
            Wtotal += horse[i].first - horse[i].second;
            if(Wtotal > Ptotal) {
                cout << i << endl;
                break;
            }
        }
        if(Wtotal > Ptotal) {
            continue;
        }
        cout << horse.size() << '\n';
    }
    return 0;
}