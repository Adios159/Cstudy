#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    for(int i = 10; i <= 100; i += 10) {
        v.push_back(i);
        cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    }
    return 0;
}