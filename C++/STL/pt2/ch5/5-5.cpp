#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for(int i = 10; i <= 50; i += 10) {
        v.push_back(i);
    }
    sort(v.begin(), v.end());

    list<int> li;
    for(int i = 10; i <= 50; i += 10) {
        li.push_back(i);
    }
    // sort(li.begin(), li.end());
    return 0;
}