#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int cnt = 0;
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'i' || S[i] == 'j') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}