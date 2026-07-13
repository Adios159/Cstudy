#include <iostream>
#include  <string>
#include <map>
using namespace std;

void printMap(map<string, int>& m) {
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        string menu = it->first;
        int price = it->second;
        cout << menu << " : " << price << endl;
    }
    cout << endl;
}

int main() {
    map<string, int> menuBoard;
    menuBoard["taco"] = 2000;
    menuBoard["kimbop"] = 2500;
    menuBoard["pizza"] = 5000;
    printMap(menuBoard);

    menuBoard.erase("taco");
    printMap(menuBoard);

    return 0;
}