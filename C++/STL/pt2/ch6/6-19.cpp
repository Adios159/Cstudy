#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lt;
    for(int i = 10; i <= 50; i += 10) {
        lt.push_back(i);
        cout << i << ' ';
    }
    cout << endl;

    list<int>::iterator it1;
    list<int>::iterator it2;
    for(it1 = lt.begin(); it1 != lt.end(); ++it1) {
        cout << *it1 << ' ';
    }
    cout << endl;
    
    ++it1; ++it1;
    it2 = lt.insert(it1, 300);
    for(it1 = lt.begin(); it1 != lt.end(); ++it1) {
        cout << *it1 << ' ';
    }
    cout << endl;

    it1 = lt.begin();
    cout << *it1 << endl;
    it2 = lt.erase(it1);
    for(it1 = lt.begin(); it1 != lt.end(); ++it1) {
        cout << *it1 << ' ';
    }
    cout << endl;

    return 0;
}