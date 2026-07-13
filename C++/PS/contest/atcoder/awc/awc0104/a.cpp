#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, vote;
    cin >> N;
    vector<pair<long long, long long>> votes;

    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        cin >> vote;
        votes.push_back(make_pair(vote, i + 1));
    }

    sort(votes.rbegin(), votes.rend());
    if(votes[0].first == votes[1].first) {
        cout << -1 << endl;
    }
    else {
        cout << votes[0].second << endl;
    }
    return 0;
}