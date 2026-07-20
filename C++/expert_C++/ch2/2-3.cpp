#include <iostream>
using namespace std;

int main() {
    const char* str1 {"Hello \"World\"!"};
    const char* str2 {"Line 1\nLine 2"};
    const char* str3 {R"(line 1
        Line 2)"};
    const char* str4 {R"(Is the following a tab character? \t)"};
    const char* str5 {R"-((Embedded) characters)-"};

    cout << str1 << endl << str2 << endl << str3 << endl;
    cout << str4 << endl << str5 << endl;
    return 0;
}