#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string S;
    cin >> S;
    S[0]  = tolower(S[0]);
    string of = "Of";
    cout  << of << S << '\n';
    return 0;
}