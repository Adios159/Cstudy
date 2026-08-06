#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string S;
    int N, max = 0;
    cin >> N;
    vector<string> word;
    for(int i = 0; i < N; i++) {
        cin >> S;
        word.push_back(S);
        if(max < S.size()) {
            max = S.size();
        }
    }

    for(int i = 0; i < word.size(); i++) {
        int diff = max - word[i].size();
        cout << string(diff / 2, '.') << word[i] << string(diff / 2, '.') << '\n';
    }
    return 0;
}