#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string S;
    char temp;
    cin >> S;
    int a = 0, ab = 0, abc = 0;

    for(char c : S) {
        switch(c) {
            case 'A':
                a++;
                break;
            case 'B':
                if(a > 0) {
                    --a;
                    ab++;
                }
                break;
            case 'C':
                if(ab > 0) {
                    ab--;
                    abc++;
                }
                break;
        }
    }
    cout << abc << endl;
    return 0;
}