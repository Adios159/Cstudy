#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    if(S[0] == S[S.size() - 1]) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}