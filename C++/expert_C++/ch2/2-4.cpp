#include <iostream>
#include <string>
#include <compare>
using namespace std;

int main() {
    string a = "12";
    string b {"34"};
    cout << a + b << endl;

    char* c = "12";
    char d[] {"12"};
    if(c == d) {
        cout << "same string\n";
    }

    auto result (a.compare(b));
    if(result < 0) {cout << "less\n";}
    if(result > 0) {cout << "greater\n";}
    if(result == 0) {cout << "equal\n";}

    auto result2 (a <=> b);
    if(is_lt(result2)) {cout << "less\n";}
    if(is_gt(result2)) {cout << "greater\n";}
    if(is_eq(result2)) {cout << "equal\n";}

    string my_string {"hello"};
    my_string += ", there";
    string my_other_string {my_string};
    if(my_string == my_other_string) {
        my_other_string[0] = 'H';
    }
    cout << my_string << endl << my_other_string << endl;

    string hello {"Hello!"};
    string world {"the world..."};
    auto position {hello.find("!")};
    if(position != string::npos) {
        hello.replace(position, 2, world.substr(3, 6));
    }
    cout << hello << endl;
}