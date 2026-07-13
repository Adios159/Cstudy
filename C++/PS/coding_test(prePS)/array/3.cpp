#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); ++j) {
            sum.insert(numbers[i] + numbers[j]);
        }
    }
    vector<int> ans(sum.begin(), sum.end());
    return ans;
}

int main() {
    vector<int> data = {5, 13, 6, 34, 2, 1, 46};
    vector<int> res = solution(data);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
