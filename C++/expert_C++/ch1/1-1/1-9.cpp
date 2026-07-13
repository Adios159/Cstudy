#include <iostream>
using namespace std;

auto add(int num1, int num2) {
    cout << "func name: " << __func__ << endl;
    return num1 + num2;
}

int main() {
    cout << add(2, 3) << endl;
    return 0;
}