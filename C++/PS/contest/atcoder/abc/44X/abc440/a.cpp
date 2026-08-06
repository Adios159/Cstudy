#include <iostream>
using namespace std;

int main() {
    int freq, oct;
    cin >> freq >> oct;

    for(int i = 0; i < oct; i++) {
        freq *= 2;
    }

    cout << freq << endl;
    return 0;
}