#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    int j = 10;
    for(int i = 0; i < v.size(); i++) {
        v[i] = j;
        j += 10;
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    v.resize(10);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    v.resize(5);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}