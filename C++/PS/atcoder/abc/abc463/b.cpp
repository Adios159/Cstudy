#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    char X;
    

    cin >> N >> X;
    vector<string> seat(N);

    for(int i = 0; i < N; i++) {
        cin >> seat[i];
        if(seat[i][X - 'A'] == 'o') {
            cout << "Yes" << endl;
            return 0;
                }
        }
    cout << "No" << endl;
    return 0;
}