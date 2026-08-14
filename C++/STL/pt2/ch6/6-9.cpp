#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(8, 1);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    v.assign(5, 2);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;

    return 0;
}