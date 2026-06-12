#include <iostream>
using namespace std;

int main() {
    int people, standard, stScore, cnt = 0;

    cin >> people >> standard;
    int scores[people];
    for(int i = 0; i < people; i++) {
        cin >> scores[i];
    }

    stScore = scores[standard - 1];
    for(int i = 0; i < people; i++) {
        if(scores[i] >= stScore && scores[i] > 0) {
            ++cnt;
        }
        else {
            continue;
        }
    }

    cout << cnt << endl;
    return 0;
}