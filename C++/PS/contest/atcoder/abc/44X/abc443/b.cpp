#include <iostream>
using namespace std;

int main() {
    long N, K, bean = 0, cnt = 0;
    cin >> N >> K;
    if(N == K) {
        cout << 0 << endl;
        return 0;
    }
    while(bean < K) {
        bean += N;
        N++;
        cnt++;
    }
    cout << cnt - 1 << endl;
    return 0;
}