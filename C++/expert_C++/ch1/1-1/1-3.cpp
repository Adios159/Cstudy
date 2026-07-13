#include <iostream>

namespace mycode {
    void foo() {
        std::cout << "Foo() is my own function" << "\n";
    }
}

int main() {
    mycode::foo();
    return 0;
}