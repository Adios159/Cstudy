#include <iostream>
#include <format>
using namespace std;

int main() {
    bool flag = true;
    int score = 92;
    double average = 82.56;

    cout << "variable type of bool" << endl;
    cout << format("size: %d\n", sizeof(flag));
    cout << "value: " << flag << endl;
    cout << "address: " << &flag << endl; 

    cout << "variable type of int" << endl;
    cout << format("size: %d\n", sizeof(score));
    cout << "value: " << score << endl;
    cout << "address: " << &score << endl; 

    cout << "variable type of double" << endl;
    cout << format("size: %d\n", sizeof(average));
    cout << "value: " << average << endl;
    cout << "address: " << &average << endl; 

    return 0;
}