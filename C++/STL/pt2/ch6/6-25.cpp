#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lt1;
    list<int> lt2;

    for(int i = 10; i <= 50; i += 10) {
        lt1.push_back(i);
        cout << i << ' ';
    }
    cout << endl;
    for(int i = 60; i <= 100; i += 10) {
        lt2.push_back(i);
        cout << i << ' ';
    }
    cout << endl;

    lt1.merge(lt2);
    list<int>::iterator it = lt1.begin();
    for(it = lt1.begin(); it != lt1.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    for(it = lt2.begin(); it != lt2.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}