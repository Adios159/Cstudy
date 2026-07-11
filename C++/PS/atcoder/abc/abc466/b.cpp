#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, C, S, color = 0;
    cin >> N >> M;
    vector<int> color_arr(M, 0);
    for(int i = 0; i < N; i++) {
        cin >> C >> S;
        color = C;
        if(color_arr[color - 1] < S) {
            color_arr[color - 1] = S;
        }
    }
    for(int i = 0; i < color_arr.size(); i++) {
        if(color_arr[i] == 0) {
            cout << -1 << ' ';
        }
        else {
            cout << color_arr[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}