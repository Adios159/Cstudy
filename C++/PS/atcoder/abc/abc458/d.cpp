#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int main() {
    int X, Q, A, B;
    multiset<int> nums;
    cin >> X;
    cin >> Q;
    nums.insert(X);
    auto it = nums.begin();
    advance(it, nums.size() / 2);
    for(int i = 0; i < Q; i++) {
        cin >> A >> B;
        nums.insert(A);
        nums.insert(B);
        if(A > *it && B > *it) {
            it++;
            cout << *it << "\n";
        }

        else if(A < *it && B < *it) {
            it--;
            cout << *it << "\n";
        }

        else {
            cout << *it << "\n";
        }
    }
    return 0;
}