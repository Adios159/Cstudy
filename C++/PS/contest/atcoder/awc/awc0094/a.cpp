#include <iostream>
using namespace std;

int main() {
    long N, W, V;
    cin >> N >> W;
    for(int i = 0; i < N; i++) {
        cin >> V;
        if(W < V) {
            continue;
        }
        else {
            W += V;
        }
    }
    cout << W << endl;
    return 0;
}