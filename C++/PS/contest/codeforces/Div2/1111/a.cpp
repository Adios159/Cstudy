#include <iostream>
using namespace std;

int main() {
    long N, M, sum = 0, temp;
    cin >> N;
    for(int i = 0; i< N; i++) {
        sum = 0;
        cin >> M;
        for(int j = 0; j < M; j++) {
            cin >> temp;
            sum += temp;
        }
        if(sum % 4 == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}