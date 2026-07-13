#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

vector<int> solution(vector<int> lst) {
    sort(lst.begin(), lst.end(), compare);
    lst.erase(unique(lst.begin(), lst.end()), lst.end());

    return lst;
}

int main() {
    vector<int> test = {2, 4, 4, 3, 1, 2, 5, 5};
    test = solution(test);
    for(int num : test)
        cout << num << ' ';
    cout << endl;

    return 0;
}