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

int binary_search(vpll arr, int target) {
    int L = 0;
    int R = arr.size() - 1;
    int M = (L + R) / 2;
    while(L <= R) {
        M = (L + R) / 2;
        if(target < arr[M].first) R = M - 1;
        if(target == arr[M].first) return arr[M].second + 1;    
        if(target > arr[M].first) L = M + 1;
    }
    return -1;
}

int main() {
    fastio;
    int N, X, A;
    vpll num;
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        cin >> A;
        num.push_back(make_pair(A, i));
    }
    int ans = binary_search(num, X);
    cout << ans << '\n';

    return 0;
}