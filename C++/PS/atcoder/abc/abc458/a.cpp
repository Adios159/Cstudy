#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int N;
    cin >> S;
    cin >> N;
    for(int i = N; i < S.size() - N; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}