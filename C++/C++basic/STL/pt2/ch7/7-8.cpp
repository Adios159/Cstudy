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
    it = ms.find(30);
    cout << "iter: " << *it << endl;

    multiset<int>::iterator lower = ms.lower_bound(30);
    multiset<int>::iterator upper = ms.upper_bound(30);
    cout << "lower iter: " << *lower << endl;
    cout << "upper iter: " << *upper << endl;

    return 0;
}