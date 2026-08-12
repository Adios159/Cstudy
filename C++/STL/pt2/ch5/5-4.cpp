#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator it;
    it = find(v.begin(), v.end(), 20);
    cout << *it << endl;

    it = find(v.begin(), v.end(), 100);
    if(it == v.end()) {
        cout << "no data" << endl;
    }
    return 0;
}