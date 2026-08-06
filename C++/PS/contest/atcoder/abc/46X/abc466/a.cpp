#include <iostream>
using namespace std;

int main() {
    int N, happy;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> happy;
        if(happy > 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}