#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while(N--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        long long cost1 = 0;
        bool possible1 = true;
        for(int i = 0; i < n; i++) {
            if(a[i] < b[i]) { possible1 = false; break; }
            cost1 += a[i] - b[i];
        }

        vector<int> sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        long long cost2 = 0;
        bool possible2 = true;
        for(int i = 0; i < n; i++) {
            if(sa[i] < sb[i]) { possible2 = false; break; }
            cost2 += sa[i] - sb[i];
        }
        if(possible2) cost2 += c;

        // 최종 판단
        if(!possible1 && !possible2) {
            cout << -1 << endl;
        } else if(!possible1) {
            cout << cost2 << endl;
        } else if(!possible2) {
            cout << cost1 << endl;
        } else {
            cout << min(cost1, cost2) << endl;
        }
    }
    return 0;
}