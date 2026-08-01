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

long long count_valid(int c, int N, int M, const vector<int>& A, const vector<int>& B) {
    int cand1 = -1;
    int cand2 = -1;
    bool intersect_found = false;
    
    for (int i = 0; i < M; ++i) {
        if (A[i] != c && B[i] != c) {
            if (!intersect_found) {
                cand1 = A[i];
                cand2 = B[i];
                intersect_found = true;
            } else {
                if (cand1 != A[i] && cand1 != B[i]) cand1 = -1;
                if (cand2 != A[i] && cand2 != B[i]) cand2 = -1;
                
                if (cand1 == -1 && cand2 == -1) {
                    break;
                }
            }
        }
    }
    
    if (!intersect_found) {
        return (long long)(N - 1);
    } else {
        long long ans = 0;
        if (cand1 != -1 && cand1 != c) ans++;
        if (cand2 != -1 && cand2 != c) ans++;
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
    }
    
    int u = A[0];
    int v = B[0];
    
    long long ans_u = count_valid(u, N, M, A, B);
    long long ans_v = count_valid(v, N, M, A, B);
    
    bool both_valid = true;
    for (int i = 0; i < M; ++i) {
        if (A[i] != u && B[i] != u && A[i] != v && B[i] != v) {
            both_valid = false;
            break;
        }
    }
    long long total = ans_u + ans_v - (both_valid ? 1 : 0);
    
    cout << total << "\n";
    
    return 0;
}