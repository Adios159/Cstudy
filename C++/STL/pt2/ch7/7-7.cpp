#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;
    multiset<int>::iterator it;

    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    ms.insert(40);
    ms.insert(80);
    ms.insert(50);
    ms.insert(10);

    for(it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}