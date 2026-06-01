#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string address("seoul seongbuk samsun 389");
    string copy(address);

    char text[] = "Love C++";

    cout << str << endl;
    cout << address << endl;
    cout << copy << endl;
    cout << text << endl;

    return 0;
}