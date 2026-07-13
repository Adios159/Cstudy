#include <iostream>
#include <compare>
using namespace std;

int main() {
    int i {11};
    strong_ordering result {i <=> 0};
    if(result == strong_ordering::less) {cout << "less" << endl;}
    if(result == strong_ordering::greater) {cout << "less" << endl;}
    if(result == strong_ordering::equal) {cout << "less" << endl;}

    if(is_lt(result)) {cout << "less" << endl;}
    if(is_gt(result)) {cout << "less" << endl;}
    if(is_eq(result)) {cout << "less" << endl;}

    return 0;
}