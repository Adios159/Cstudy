#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, ans;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9' ) {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}