#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s = to_string(N);
    if((s[0] == s[1]) && (s[1] == s[2])) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}