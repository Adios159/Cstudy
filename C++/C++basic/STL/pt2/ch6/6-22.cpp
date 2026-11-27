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
    
    lt.reverse();
    list<int>::iterator it = lt.begin();
    for(; it != lt.end(); ++it) {
        cout << *it  << ' ';
    }
    cout << endl;
    return 0; 
}