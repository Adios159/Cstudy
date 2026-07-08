#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    long long count = 0;
    cin >> S;
    for(size_t i = 0; i < S.size(); i++) {
        if(S[i] == 'C') {
            count += min(i, S.size() - 1 - i) + 1;
        }
    }
    cout << count << endl;
    return 0;
}