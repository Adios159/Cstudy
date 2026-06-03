#include <iostream>
#include <string>
using namespace std;

const long long MOD = 998244353;

int main() {
    string str;
    cin >> str;
    int n = str.length();

    long long cnt = 0;
    long long run = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (str[i] != str[i + 1]) {
            run++;
        } else {
            run = 1;
        }
        cnt = (cnt + run) % MOD;
    }

    cnt = (cnt + 1) % MOD;

    cout << cnt << endl;

    return 0;
}