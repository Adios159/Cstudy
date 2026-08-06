#include <iostream>
#include <vector>
#include <ranges>
int main() {
    using namespace std;
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto&& a : A) {
        cin >> a;
        --a;
    }
    vector<int> ans(N);
    for (int i : views::iota(0, N) | views::reverse) { 
        if (i == A[i]) { 
            ans[i] = i; 
        } else { 
            ans[i] = ans[A[i]]; 
        }
    }
    for (int a : ans) {
        cout << a + 1 << " ";
    }
    cout << endl;
    return 0;
}