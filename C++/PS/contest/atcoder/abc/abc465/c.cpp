#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N, num;
    string S;
    bool flip = false;
    cin >> N;
    cin >> S;
    deque<int> numerics;
    for(int i = 0; i < N; i++) {
        num = i + 1;
        if(S[i] == 'o') {
            flip = !flip;
            if(flip == true) {
                numerics.push_back(num);
            }
            else {
                numerics.push_front(num);
            }
        }
        else {
            if(flip == true) {
                numerics.push_front(num);
            }
            else {
                numerics.push_back(num);
            }
        }
    }

    if(flip == true) {
        reverse(numerics.begin(), numerics.end());
        for(int i = 0; i < numerics.size(); i++) {
            cout << numerics[i] << ' ';
        }
    }
    else {
        for(int i = 0; i < numerics.size(); i++) {
            cout << numerics[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}