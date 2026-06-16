#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char cmd[80];
    while(true) {
        cout <<"enter exit to exit: ";
        cin.get(cmd, 80);
        if(strcmp(cmd, "exit") == 0) {
            cout << "shuting down...";
            return 0;
        }
        else
            cin.ignore(1);
    }
}