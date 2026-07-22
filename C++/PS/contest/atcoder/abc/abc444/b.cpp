#include <iostream>
using namespace std;

int main() {
    int N, K, sum = 0, cnt = 0;
    cin >> N >> K;
    for(int i = 0; i <= N; i++) {
        int temp = i;
        sum = 0;
        while(temp != 0) {
            sum += temp % 10;
            temp = temp / 10;
        }
        if(sum == K) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}