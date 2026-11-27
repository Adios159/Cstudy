#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    it = v.begin();
    it += 2;
    cout << *it << endl;
    return 0;
}