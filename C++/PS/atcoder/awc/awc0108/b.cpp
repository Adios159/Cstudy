#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string password = "sayounara";
    string word;

    for(int i = 0; i < N; i++) {
        cin >> word;
        if(word.size() == 0) {
            cout << "No" << endl;
            continue;
        }
        int passIdx = 0;
        for(int j = 0; j < word.size(); j++) {
            if(password[passIdx] == word[j]) {
                ++passIdx;
                if(passIdx == 9) {
                    cout << "Yes" << endl;
                    break;
                }
            }
            if(j == word.size() - 1) {
                if(passIdx != password.size()) {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}