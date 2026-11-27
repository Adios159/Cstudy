#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lt;
    lt.push_back(20);
    lt.push_back(40);
    lt.push_back(10);
    lt.push_back(30);
    lt.push_back(50);
    
    list<int>::iterator it = lt.begin();
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it  << ' ';
    }
    cout << endl;
    
    lt.sort();
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it  << ' ';
    }
    cout << endl;
    return 0; 
}