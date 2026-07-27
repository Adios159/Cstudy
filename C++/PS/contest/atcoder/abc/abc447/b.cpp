#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    string erase = "";
    int max = 0;
    cin >> S;
    vector<int> counter(26);
    for(char c: S) {
        counter[(c - 'a')]++;
    }
    for(int i = 0; i < counter.size(); i++) {
        if(max < counter[i]) {
            max = counter[i];
        }
    }
    for(int i = 0; i < counter.size(); i++) {
        if(max == counter[i]) {
            erase += ((char)(i + (int)('a')));
        }
    }
    for(char c : erase) {
        S.erase(remove(S.begin(), S.end(), c), S.end());
    }
    cout << S << endl;
    return 0;
}