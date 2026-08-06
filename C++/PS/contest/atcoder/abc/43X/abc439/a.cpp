#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int power = pow(2, N);
    cout << power - (2 * N) << '\n';
    return 0;
}