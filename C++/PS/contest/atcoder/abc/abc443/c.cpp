#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long  N, T, A;
    cin >> N >> T;
    long long open_since = 0, total = 0;
    for(int i = 0; i < N; i++) {
        cin >> A;
        if(A >= open_since) {
            total += A - open_since;
            open_since = A + 100;
        }
        else {
            continue;
        }
    }
    total += max((long long)0, T - open_since);
    cout << total << '\n';
    return 0;
}