#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "HelloWorld";
    int N;
    cin >> N;
    word.erase(N - 1, 1);
    cout << word << endl;
    return 0;
}