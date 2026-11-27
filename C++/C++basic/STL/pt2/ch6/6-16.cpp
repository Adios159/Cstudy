#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    for(int i = 10; i <= 50; i += 10) {
        dq.push_back(i);
        cout << i << ' ';
    }
    cout << endl;
    dq.push_front(100);
    dq.push_front(200);
    for(int i = 10; i <= 50; i += 10) {
        dq.push_back(i);
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}