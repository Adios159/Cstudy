#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for(int i = 10; i <= 50; i += 10) {
        v.push_back(i);
    } 
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.max_size() << endl;
}