#include <cstdio>
#include <iostream>
using namespace std;

bool compare(int a, int b, int& min, int& max) {
    if(a > b) {
        min = b;
        max = a;
        return false;
    }
    else if(a == b) {
        min = max = a;
        return true;
    }
    else {
        min = a;
        max = b;
        return false;
    }
}

int main() {
    int a, b, min, max;
    cout << "input two numbers: ";
    cin >> a >> b;
    bool res = compare(a, b, min, max);
    if(res == true)
        cout << "both numbers are same" << endl;
    else    
        printf("min: %d\nmax: %d\n", min, max);
    
    return 0;
}