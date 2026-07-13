#include <iostream>
#include <string>
using namespace std;

bool equals(string x, string y) {
    if(x == y)
        return true;
    else
        return false;
}

bool equals(string x, string y, int num) {
    string subX = x.substr(0, num);
    string subY = y.substr(0, num);
    if(subX == subY)
        return true;
    else
        return false;
}

bool equals(string x, string y, int num, string z) {
    string subX = x.substr(0, num);
    string subY = y.substr(0, num);
    string subZ = z.substr(0, num);

    if(subX == subY && subY == subZ)
        return true;
    else
        return false;
}


int main() {
    string x = "Prof. Hwang";
    string y = "Prof. kim";
    string z = "Prof. Lee";

    if(equals(x, y)) cout << "same string" << endl;
    if(equals(x, y, 3)) cout << "same string as 3" << endl;
    if(equals(x, y, 5, z)) cout << "same string as 5" << endl;
}