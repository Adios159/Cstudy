#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    int j = 10;
    for(int i = 0; i < v.size(); i++) {
        v[i] = j;
        j += 10;
    }
    vector<int>::iterator it = v.begin();
    vector<int>::const_iterator cit = v.begin();

    cout << *it << endl;
    cout << *cit << endl;

    cout << *++it << endl;
    cout << *++cit << endl;

    return 0;
}