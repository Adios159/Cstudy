#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, A, B;
    int change = 0, finally = 0;
    string S;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A >> B >> S;
        change += B - A;
        if(S == "take") {
            finally += B - A;
        }
        else {
            continue;
        }
    }
    cout << change - finally << '\n';
    return 0;
}