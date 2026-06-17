#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for(int i = 1; i <= N; i++) {
        if(B[A[i]] != i) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}