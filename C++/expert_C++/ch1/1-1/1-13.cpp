#include <iostream>
#include <format>
#include <string>
using namespace std;

int main() {
    string my_string = "Hello World!";
    cout << format("my string: {}\n", my_string);
    cout << format("value of first element: {}\n", my_string[0]);
    return 0;
}