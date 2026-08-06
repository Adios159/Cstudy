#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    int cnt = 0;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N - 1);
    vector<int> f;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    f.push_back(0);
    for(int i = 0; i< N - 1; i++) {
        int temp = f[i] ^ ((B[i] ^ A[i]) ^ A[i + 1]);
        f.push_back(temp);
        if(temp == 1) {
            cnt++;
        }
    }
    cout << ((cnt < (N - cnt)) ? cnt : N - cnt) << '\n';
    return 0;
}