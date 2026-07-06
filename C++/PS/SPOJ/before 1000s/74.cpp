#include <iostream>
using namespace std;

int main() {
    int divisor_sum[500001] = {0};
    for(int i = 1; i <= 500000; i++) {
        for(int multiple = 2 * i; multiple <= 500000; multiple += i) {
            divisor_sum[multiple] += i;
        }
    }

    int N, num;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        cout << divisor_sum[num] << endl;
    }
    return 0;
}