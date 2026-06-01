#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 0;
    string word;

    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> word;
        if(word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
        }
        else {
            cout << word << endl;
        }
    }

    return 0;
}