#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lt;
    cout << "lt: ";
    for(int i = 10; i <= 50; i += 10) {
        lt.push_back(i);
        cout << i << ' ';
    }
    cout << endl;

    list<int> lt2;
    for(int i = 100; i <= 500; i += 100) {
        lt2.push_back(i);
        cout << i << ' ';
    }
    cout << endl;

    list<int>::iterator it = lt.begin();
    it++;
    it++;
    lt.splice(it, lt2);
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}