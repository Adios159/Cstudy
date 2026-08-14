#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    if(v1 == v2) {
        cout << "v1 == v2" << endl;
    }
    if(v1 != v2) {
        cout << "v1 != v2" << endl;
    }
    if(v1 < v2) {
        cout << "v1 < v2" << endl;
    }

    return 0;
}