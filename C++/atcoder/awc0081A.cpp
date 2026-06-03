#include <iostream>
#include <string>
using namespace std;

int main() {
    string order, written;
    int tCase, cnt = 0;

    cin >> tCase;

    for(int i = 0; i < tCase; i++) {
        cin >> order >> written;
        if(order != written)
            cnt++;
    }

    cout << cnt << endl;
}