#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, score, count = 0;
    vector<int> certified;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> score;
        if(score >= K) {
            certified.push_back(i + 1);
        }
    }

    if(certified.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(certified.begin(), certified.end());
    for(int i = 0; i + 1 < certified.size(); i++) {
        if(certified[i + 1] - certified[i] != 1) {
            ++count;
        } 
        else {
            continue;
        }
    }
    cout << count + 1 << endl;
    return 0;
}