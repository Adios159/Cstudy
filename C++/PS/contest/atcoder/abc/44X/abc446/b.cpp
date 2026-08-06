#include <iostream>
#include <vector>
using namespace std;

int main() {
    short N, M, L, X;
    cin >> N >> M;
    vector<bool> is_taken(M);
    for(short i = 0; i < N; i++) {
        cin >> L;
        bool end = false;
        for(short j = 0; j < L; j++) {
            cin >> X;
            if((end == false) && (is_taken[X - 1] == false)) {
                cout << X << '\n';
                is_taken[X - 1] = true;
                end = true;
            }
            else {
                continue;
            }
        }
        if(end == false) {
            cout << 0 << endl;
        }
    }
    return 0;
}