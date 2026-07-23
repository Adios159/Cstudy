#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, A, temp;
    int last_zero = 0;
    cin >> N;
    vector<int> A_val(N);

    for(int i = 0; i < N; i++) {
        cin >> A;
        A_val[i] = A;
    }
    sort(A_val.rbegin(), A_val.rend());
    vector<int> diff(A_val[0] + 10);
    for(int i = 0; i < A_val.size(); i++) {
        diff[0] += 1;
        diff[A_val[i]] -= 1;
    }

    for(int i = 1; i < diff.size(); i++) {
        diff[i] += diff[i-1];
    }

    for(int i = 0; i < diff.size(); i++) {
        if(diff[i] > 9) {
            diff[i + 1] += diff[i] / 10;
            diff[i] %= 10;
        }
    }

    for(int i = diff.size() - 1; i >= 0; --i) {
        if(diff[i] != 0) {
            break;
        }
        last_zero++;
    }

    int start = diff.size() - 1 - last_zero;
    for(int i = start; i >= 0; --i) {
        cout << diff[i];
    }
    cout << '\n';
    return 0;
}