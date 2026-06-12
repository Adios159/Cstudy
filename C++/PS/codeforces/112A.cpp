#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] >= 65 && str1[i] <= 90) {
            str1[i] = tolower(str1[i]);
        }
    }
    for(int j = 0; j < str2.size(); j++) {
        if(str2[j] >= 65 && str2[j] <= 90) {
            str2[j] = tolower(str2[j]);
        }
    }

    for(int k = 0; k < str1.size(); k++) {
        if(str1[k] < str2[k]) {
            cout << -1 << endl;
            return 0;
        }

        else if(str1[k] > str2[k]) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}