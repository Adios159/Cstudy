#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

int main() {
    vector<int> test = {10, 3, 5, 99, 7, 15, 41};
    test = solution(test);
    for(int num : test) 
        cout << num << ' ';
    cout << endl;

    return 0;
}