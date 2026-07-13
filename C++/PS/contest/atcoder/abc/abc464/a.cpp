#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int cnt[2] = {0, 0};
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'E')
            ++cnt[0];
        else    
            ++cnt[1];
    }
    if(cnt[0] > cnt[1])
        cout << "East" << endl;
    else
        cout << "West" << endl;
    
    return 0;
}