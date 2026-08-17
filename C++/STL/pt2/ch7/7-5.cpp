#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    s.insert(40);
    s.insert(50);
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(70);

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    set<int>::iterator it = s.find(30);
    if(it != s.end()) {
        cout << "we have " << *it << endl;
    }
    else {
        cout << "we don't have 30" << endl;
    }
    return 0;
}