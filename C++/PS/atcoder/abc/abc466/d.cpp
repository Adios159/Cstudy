#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<int> r(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> r[i] >> c[i];
    }
    
    vector<bool> seen_r(n + 1, false);
    vector<bool> seen_c(n + 1, false);
    
    int ans = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (!seen_r[r[i]] && !seen_c[c[i]]) {
            ans++;
        }
        seen_r[r[i]] = true;
        seen_c[c[i]] = true;
    }
    
    cout << ans << "\n";
    
    return 0;
}