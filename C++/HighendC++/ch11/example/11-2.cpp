#include <iostream>
using namespace std;

void get1() {
    int ch;
    while((ch = cin.get()) != EOF) {
        cout.put(ch);
        if(ch == '\n')
            break;
    }
}

void get2() {
    char ch;
    while(true) {
        cin.get(ch);
        if(cin.eof()) break;
        cout.put(ch);
        if(ch == '\n')
            break;
    }
}

int main() {
    get1();
    get2();

    return 0;
}