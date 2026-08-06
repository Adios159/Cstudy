#include <iostream>
using namespace std;

int main() {
    int N;
    string word;
    cin >> N;
    cin >> word;
    if(N == 1) {
        if(word[0] == 'l' || word[0] == 'v') {
            cout << 1 << endl;
            return 0;
        }
    }
    for(int i = 0; i + 1 < N; i++) {
        if(word[i] == 'l' && word[i + 1] == 'v') {
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i = 0; i < N; i++) {
        if(word[i] == 'l' || word[i] == 'v') {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}