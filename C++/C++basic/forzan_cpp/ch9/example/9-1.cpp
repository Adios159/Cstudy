#include <iostream>
using namespace std;

int main() {
    int score = 92;
    int& rScore = score;
    cout << "usign data with data variable: " << score << endl;
    cout << "using data with reference variiable: " << rScore << endl;
    return 0; 
}