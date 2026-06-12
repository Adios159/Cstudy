#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long N, M;
    cin >> N >> M;

    long long result = 1;
    for(int i = 0; i < N; i++) {
        long long p;
        cin >> p;
        result = lcm(result, p);
        if(result > M) {      
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}