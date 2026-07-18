#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    if(M * 100 * 100 >= 25 * N * N) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}