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

const int MAX_BITS = 20;
const int MAX_NODES = 11000000; 

int ch[MAX_NODES][2];
int sz[MAX_NODES];
int val[MAX_NODES];
int node_cnt = 1;
int v_arr[500005];

void update(int u, int d) {
    val[u] = 0;
    int l = ch[u][0];
    int r = ch[u][1];
    
    if (l) val[u] ^= val[l];
    if (r) {
        val[u] ^= val[r];
        // If the right child has an odd number of elements, the d-th bit contributes to the XOR sum
        if (sz[r] & 1) {
            val[u] ^= (1 << d);
        }
    }
}

// Inserts a value into the LSB Trie
void insert(int &u, int d, int v) {
    if (!u) u = ++node_cnt;
    sz[u]++;
    if (d == MAX_BITS) {
        val[u] = 0;
        return;
    }
    int bit = (v >> d) & 1;
    insert(ch[u][bit], d + 1, v);
    update(u, d);
}

// Removes a specific value from the LSB Trie
void remove_val(int u, int d, int v) {
    sz[u]--;
    if (d == MAX_BITS) {
        val[u] = 0;
        return;
    }
    int bit = (v >> d) & 1;
    remove_val(ch[u][bit], d + 1, v);
    update(u, d);
}

// Removes all `0`s from the Trie by walking the pure left (bit-0) branch
int remove_zeros(int u, int d) {
    if (!u || sz[u] == 0) return 0;
    int removed = 0;
    if (d == MAX_BITS) {
        removed = sz[u];
        sz[u] = 0;
        val[u] = 0;
        return removed;
    }
    removed = remove_zeros(ch[u][0], d + 1);
    sz[u] -= removed;
    update(u, d);
    return removed;
}

// Subtracts 1 from all values uniformly within the Trie
void sub(int u, int d) {
    if (!u || sz[u] == 0) return;
    if (d == MAX_BITS) return;

    // Swap the 0 and 1 bits 
    swap(ch[u][0], ch[u][1]);

    // Originally bit 0, became bit 1 -> Requires a borrow from the next higher bit
    if (ch[u][1] && sz[ch[u][1]] > 0) {
        sub(ch[u][1], d + 1);
    }

    update(u, d);
}


int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    int global_sub = 0;
    int root = 1;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            
            // True positive magnitude of A_x
            int C = max(0, v_arr[x] - global_sub);
            
            // Re-map it within our Trie
            if (C > 0) {
                remove_val(root, 0, C);
            }
            insert(root, 0, C + 1);
            
            // Sync its new abstract stored array state
            v_arr[x] = C + 1 + global_sub;
            
        } else {
            global_sub++;
            sub(root, 0);          // Decrements all elements in the Trie
            remove_zeros(root, 0); // Prune any element that just decayed to 0
        }
        
        // Output XOR Sum (available globally cleanly at the root node)
        cout << val[root] << "\n";
    }

    return 0;
}