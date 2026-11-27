#include <bits/stdc++.h>
using namespace std;

bool Predicate(int first, int second) {
    return second - first <= 0;
}

int main() {
    list<int> lt;
    cout << "lt: ";
    for(int i = 10; i <= 50; i += 10) {
        lt.push_back(i);
    }
    cout << endl;
    lt.push_back(10);
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(40);
    lt.push_back(10);
    lt.push_back(30);
    lt.push_back(20);
    lt.push_back(50);

    list<int>::iterator it = lt.begin();
    for(; it != lt.end(); ++it) {
        cout << *it  << ' ';
    }
    cout << endl;

    lt.unique(Predicate);
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it  << ' ';
    }
    cout << endl;
    return 0; 
}