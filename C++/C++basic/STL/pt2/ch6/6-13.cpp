#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    int j = 10;
    for(int i = 0; i < v.size(); i++) {
        v[i] = j;
        j += 10;
    }
    vector<int>::iterator it;
    vector<int>::iterator it2;
    it2 = v.insert(it, 100);
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    it = v.begin() + 2;
    it2 = v.erase(it);
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }

    it2 = v.erase(v.begin() + 1, v.end());
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}