#include <iostream>
using namespace std;

int main() {
    int N, M, remain, cnt = 0;
    cin >> N >> M;

    while(true) {
        remain = N % M;
        cnt++;
        if(remain == 0)
            break;
        M = remain;
    }

    cout << cnt << endl;
    return 0;
}