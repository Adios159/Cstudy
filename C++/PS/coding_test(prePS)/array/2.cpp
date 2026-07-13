#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lst) {
    sort(lst.end(), lst.begin());
    vector<int> ans;
    for(int i = 0; i < lst.size(); i++) {
        if(lst[i] == lst[i + 1]) {
            if(ans.empty() || ans.back() != lst[i]) {
                ans.push_back(lst[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> test = {4, 2, 2, 1, 3, 4};
    test = solution(test);
    for(int num : test)
        cout << num << ' ';
    cout << endl;
    return 0;

}