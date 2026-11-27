#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    int j = 10;
    for(int i = 0; i < v.size(); i++) {
        v[i] = j;
        j += 10;
    }
    vector<int>::iterator it = v.begin() + 2;
    vector<int>::iterator it2;
    it2 = v.insert(it, 100);
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    cout << "*it2: " << *it2 << endl;
    return 0;
}