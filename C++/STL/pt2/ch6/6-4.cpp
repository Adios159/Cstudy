#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.reserve(8);
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    for(int i = 10; i <= 100; i += 10) {
        v.push_back(i);
        cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}