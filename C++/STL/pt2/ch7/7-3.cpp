#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    pair<set<int>::iterator, bool> pr;

    s.insert(40);
    s.insert(50);
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(70);
    pr = s.insert(90);

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    s.insert(pr.first, 85);
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}