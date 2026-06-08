#include <iostream>
#include <string>
using namespace std;

string erase(string x) {
    for(int i = 0; i < (int)x.length(); i++) {
        if(x[i] == ' ') {
            x.erase(i, 1);  
            i--;             
        }
    }
    return x;
}

string erase(string x, string target) {
    int tlen = target.length();
    for(int i = 0; i < (int)x.length(); i++) {
        if(x.substr(i, tlen) == target) {
            x.erase(i, tlen);
            i--;
        }
    }
    return x;
}

string erase(string x, string target, string replace) {
    int tlen = target.length();
    int rlen = replace.length();
    for(int i = 0; i < (int)x.length(); i++) {
        if(x.substr(i, tlen) == target) {
            x.replace(i, tlen, replace);  // i번째부터 tlen개를 replace로 교체
            i += rlen - 1;                // replace 길이만큼 건너뜀
        }
    }
    return x;
}

int main() {
    string a = erase("Hello  world  yaho");
    string b = erase("Hello  world  yaho", "ll");
    string c = erase("Hello  world  yaho", "o", "77");

    cout << a << endl << b << endl << c << endl;

    return 0;
}
