#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, taka = 0, aoki = 0, score;
    cin >> N;
    vector<long long> card;
    for(int i = 0; i < N; i++) {
        cin >> score;
        card.push_back(score);
    }
    sort(card.begin(), card.end());

    for(int i = card.size() - 1; i * 2 > 0; i -= 2) {
        aoki += card[i - 1];
        taka += card[i];
    }
    if(card.size() % 2 == 1) {
        taka += card[0];
    }
    cout << taka - aoki << endl;
    return 0;
}