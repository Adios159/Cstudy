#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int open = 0, max_depth= 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            open++;
        }
        else {
            --open;
        }
        if(max_depth < open) {
            max_depth = open;
        }
    }
    cout << max_depth << '\n';
    return 0;

}