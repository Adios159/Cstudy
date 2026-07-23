#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long N;
    cin >> N;
    vector<int> happy(N);
    for(int x = 1; 2 * x * x < N; x++) {
        for(int y = x + 1; (x * x) + (y * y) <= N; y++) {
            long res = (x * x) + (y * y);
            happy[res - 1]++;
        }
    } 

    int cnt = 0;
    vector<long> res;
    for(int i = 0; i < happy.size(); i++) {
        if(happy[i] == 1) {
            res.push_back(i + 1);
            cnt++;
        }
    }

    cout << cnt << '\n';
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}