#include <iostream>
#include <vector>
using namespace std;

int main() {
    string sky[1001];
    int row, col;
    vector<pair<int,int>> stars;

    cin >> row >> col;
    for(int i = 0; i < row; i++) {
        cin >> sky[i];
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(sky[i][j] == 'T') {
                stars.push_back({i + 1, j + 1});
            }
        }
    }

    cout << stars.size() << endl;
    for(int i = 0; i < stars.size(); i++) {
        cout << stars[i].first << " " << stars[i].second << endl;
    }

    return 0;
}