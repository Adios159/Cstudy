#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text1[] = "abcdef";
    size_t s1 = sizeof(text1);
    size_t s2 = strlen(text1);
    cout << s1 << ' ' << s2 << endl;

    const char* text2 {"abcdef"};
    size_t s3 = sizeof(text2);
    size_t s4 = strlen(text2);
    cout << s3 << ' ' << s4 << endl;

    return 0;
}