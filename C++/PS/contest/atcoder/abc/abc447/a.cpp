#include <iostream>
using namespace std;

int main() {
    short N, M;
    cin >> N >> M;
    if((M + (M - 1)) <= N)  {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}