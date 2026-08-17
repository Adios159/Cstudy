#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    for(int i = 10; i <= 60; i += 10) {
        s.insert(i);
        cout << i << ' ';
    }
    cout << endl;

    cout << "count element 50: " << s.count(50) << endl;
    cout << "count element 50: " << s.count(120) << endl;

    return 0;
}