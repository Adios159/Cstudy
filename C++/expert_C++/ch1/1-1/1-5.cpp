#include <iostream>
#include <format>
#include <limits>
using namespace std;

int main() {
    cout << "int:\n";
    cout << format("Max int value: {}\n", numeric_limits<int>::max());
    cout << format("Max int value: {}\n", numeric_limits<int>::min());
    cout << format("Max int value: {}\n", numeric_limits<int>::lowest());

    cout << "\ndoouble:\n";
    cout << format("Max double value: {}\n", numeric_limits<double>::max());
    cout << format("Max double value: {}\n", numeric_limits<double>::min());
    cout << format("Max double value: {}\n", numeric_limits<double>::lowest());

    cout << "\nlong long:\n";
    cout << format("Max long long value: {}\n", numeric_limits<long long>::max());
    cout << format("Max long long value: {}\n", numeric_limits<long long>::min());
    cout << format("Max long long value: {}\n", numeric_limits<long long>::lowest());

    return 0;
}