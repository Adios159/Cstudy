#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    pair<set<int>::iterator, bool> pr;

    pr = s.insert(50);
    s.insert(40);
    s.insert(80);

    if(pr.second == true) {
        cout << *pr.first << "insert complete" << endl;
    }
    else {
        cout << *pr.first << "insert fail" << endl;
    }

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    pr = s.insert(50);
    if(pr.second == true) {
        cout << *pr.first << "insert complete" << endl;
    }
    else {
        cout << *pr.first << "insert fail" << endl;
    }

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}