#include <iostream>
#include <cstring>
using namespace std;

char* copy_string(const char* str) {
    char* result {new char[strlen(str) + 1]};
    strcpy(result, str);
    return result;
}

char* append_string(const char* str1, const char* str2, const char* str3) {
    char* result {new char[strlen(str1) + strlen(str2) + strlen(str3) + 1]};
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}

int main() {
    char* str1 {"Hello"};
    char* str2 {" World"};
    char* str3 {"!"};

    char* str4 = copy_string(str1);
    char* str5 = append_string(str1, str2, str3);

    cout << str4 << endl;
    cout << str5 << endl;
    return 0;
}