#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for(int i = 10; i <= 50; i += 10) {
        v.push_back(i);
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    reverse_iterator<vector<int>::iterator> rit(v.end());
    reverse_iterator<vector<int>::iterator> end_rit(v.begin());
    for(; rit != end_rit; ++rit) {
        cout << *rit << ' ';
    }
    cout << endl;
    return 0;
}