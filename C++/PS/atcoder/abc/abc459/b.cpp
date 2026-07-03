#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int N;
    int nums[10];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        switch(word[0]) {
            case 'a': case 'b': case 'c':
                nums[i] = 2;
                break;
            case 'd': case 'e': case 'f':
                nums[i] = 3;
                break;
            case 'g': case 'h': case 'i':
                nums[i] = 4;
                break;
            case 'j': case 'k': case 'l':
                nums[i] = 5;
                break;
            case 'm': case 'n': case 'o':
                nums[i] = 6;
                break;
            case 'p': case 'q': case 'r': case 's':
                nums[i] = 7;
                break;
            case 't': case 'u': case 'v':
                nums[i] = 8;
                break;
            case 'w': case 'x': case 'y': case 'z':
                nums[i] = 9;
                break;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}