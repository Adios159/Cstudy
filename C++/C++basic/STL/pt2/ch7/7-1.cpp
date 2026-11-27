#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(70);
    s.insert(50);
    s.insert(30);
    s.insert(70);
    s.insert(90);
    s.insert(100);

    set<int>::iterator it = s.begin();
    for(it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}