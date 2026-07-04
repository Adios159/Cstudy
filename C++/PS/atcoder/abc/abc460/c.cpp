#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int rice, fish, N, M, bigFish = 0;
    int count = 0;
    int fi = 0, rj = 0;
    vector<int> rices;
    vector<int> fishes;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> rice;
        rices.push_back(rice * 2);
    }
    sort(rices.begin(), rices.end());

    for(int i = 0; i < M; i++) {
        cin >> fish;
        fishes.push_back(fish);
        if(bigFish < fish) {
            bigFish = fish;
        }
    }
    sort(fishes.begin(), fishes.end());

    while(fi < fishes.size() && rj < rices.size())  {
        if(fishes[fi] <= rices[rj]) {
            count++;
            fi++;
            rj++;
        }
        else {
            rj++;
        }
    }
    cout << count << endl;  
    return 0;
}