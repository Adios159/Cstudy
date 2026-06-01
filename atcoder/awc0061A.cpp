#include <iostream>
using namespace std;

int main() {
    int member, like, vote;
    int result = 0;
    int song;
    cin >> member >> song;
    int vResult[100001] = {};

    for(int i = 0; i < member; i++) {
        cin >> vote;
        for(int j = 0; j < vote; j++) {
            cin >> like;
            vResult[like - 1]++;
        }
    }

    for(int k = 0; k < song; k++) {
        if(vResult[k] == member) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}