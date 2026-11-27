#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    for(int i = 10; i <= 50; i += 10) {
        dq.push_back(i);
        cout << i << ' ';
    }
    cout << endl;
    deque<int>::iterator it;
    deque<int>::iterator it2;
    for(it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    it = dq.begin() + 2;
    it2 = dq.insert(it, 500);
    for(it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
