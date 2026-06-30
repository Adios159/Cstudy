#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, time;
    cin >> N;
    vector<pair<int, int>> horse;

    for(int i = 0; i < N; i++) {
        cin >> time;
        horse.push_back(make_pair(time, i + 1));
    }
    
    sort(horse.begin(), horse.end());
    cout << horse[0].second << " " << horse[1].second << " " << horse[2].second << endl;
    return 0;
}