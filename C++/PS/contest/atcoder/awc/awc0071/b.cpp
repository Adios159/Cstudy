#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    long long N, cnt = 0, length = 0;
    string S, A;
    cin >> N >> S;
    char pivot = S[0];
    A += pivot;
    vector<pair<char, int>> lengths;
    for(size_t i = 1; i <  S.size(); i++) {
        if(pivot != S[i]) {
            length++;
            A += S[i];
            lengths.push_back(make_pair(pivot, length));
            pivot = S[i];
            length = 0;
        }
        else {
            length++;
        }
    }
    length++;
    lengths.push_back(make_pair(pivot, length));  
    if(lengths.size() < 3) {
        cout << 0 << '\n';
        return 0;
    }  
    for(size_t i = 0; i <= A.size() - 3; i++) {
        if(A[i] == A[i + 2]) {
            cnt += (long long)lengths[i].second * lengths[i + 2].second;
        }
    }
    cout << cnt << '\n';
    return 0;
}