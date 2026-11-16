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
typedef string str;
typedef vector<bool> vb;

// ---------- 매크로 ----------
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define MAKE_VEC(name, n) std::vector<int> name(n); std::iota(name.begin(), name.end(), 1)

// ---------- 상수 ----------
const int INF = 1e9;
const ll LLINF = 4e18;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979;

int main() {
    fastio;
    int N, Q, K;
    cin >> N >> Q;
    vector<int> cards(N); 
    iota(cards.begin(), cards.end(), 1);
    while(Q--) {
        cin >> K;
        int front = 0, rear = K - 1;
        for(int j = 0; j < K / 2; j++) {
            cards[front] *= -1;
            cards[rear] *= -1;
            swap(cards[front], cards[rear]);
            front++; --rear;
        }
        if(K % 2 == 1) {
            cards[K / 2] *= -1;
        }

    }
    for(int i = 0; i < sz(cards); i++) {
        cout << cards[i] << '\n';
    }
    return 0;
}