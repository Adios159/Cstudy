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
    int H, W, N, A, B;
    int num;
    cin >> H >> W >> N;
    int board[3][5];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> num;
            board[i][j] = num;
        }
    }
    num = 0;
    vi cnt(H);
    vi nums;
    for(int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < H; j++) {
            for(int k = 0; k < W; k++) {
                if(nums[i] == board[j][k]) {
                    cnt[j]++;
                }
            }
        }
    }
    cout << *max_element(all(cnt)) << endl;
    return 0;
}