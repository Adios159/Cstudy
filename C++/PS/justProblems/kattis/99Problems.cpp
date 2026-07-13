#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, Q, D, T, DT;
    cin >> N >> Q;
    multiset<int> problems;
    for(int i = 0; i < N; i++) {
        cin >> D;
        problems.insert(D);
    }

    for(int i = 0; i < Q; i++) {
        cin >> T >> DT;
        if(T == 1) {
            auto temp = problems.upper_bound(DT);
            if(temp == problems.end()) {
                cout << -1 << endl;
            }
            else {
                cout << *temp << endl;
                problems.erase(temp);
            }
        }
        else if(T == 2) {
            auto temp = problems.upper_bound(DT);
            if(temp == problems.begin()) {
                cout << -1 << endl;
            }
            else {
                cout << *--temp << endl;
                problems.erase(temp);
            }
        }
    }
    return 0;
}