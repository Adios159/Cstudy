#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int j = 10;
    for(int i = 0; i < v.size(); i++) {
        v[i] = j;
        j += 10;
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    cout << "size: " << v.size() << " capacity: " << v.capacity();
    cout << endl;
    v.clear();
    cout << "size: " << v.size() << " capacity: " << v.capacity();
    cout << endl;
}