#include <iostream>
#include <string>
using namespace std;

void star(int a = 5) {
    for(int i = 0; i < a; i++) cout << '*';
    cout << endl;
}

void msg(int id, string text) {
    cout << id << ' ' << text << endl;
}

int main() {
    star();
    star(10);
    cout << endl;

    msg(10, " ");
    msg(10, "hello");
    cout << endl;

    return 0;
}