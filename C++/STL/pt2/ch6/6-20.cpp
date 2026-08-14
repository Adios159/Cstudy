#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lt;
    for(int i = 10; i <= 50; i += 10) {
        lt.push_back(i);
        cout << i << ' ';
    }
    cout << endl;
    lt.push_back(10);
    lt.push_back(10);
    for(list<int>::iterator it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    lt.remove(10);
    for(list<int>::iterator it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}