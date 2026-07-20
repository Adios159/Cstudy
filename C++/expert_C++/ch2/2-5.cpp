#include <iostream>
#include <format>
#include <string>
using namespace std;

int main() {
    long double d = 3.14L;
    string s1 = to_string(d);
    cout << d << '\n';

    const string to_parse {"  123USD"};
    size_t index {0};
    int value = stoi(to_parse, &index);
    cout << format("parsed value: {}\n", value);
    cout << format("First non-parsed character: {}\n", to_parse[index]);

    return 0;
}