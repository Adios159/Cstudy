#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, height, time, problems ;

    cin >> N;
    vector<vector<int>> cases;
    vector<int> tCase(2);
    vector<int> outTime(3000002);

    for(int i = 0; i < N; i++) {
        cin >> tCase[0] >> tCase[1];
        cases.push_back(tCase);
    }

    cin >> problems;
    for(int i = 0; i < problems; i++) {
        cin >> outTime[i];
    }

    vector<int> H(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        H[i] = cases[i][0];  // 또는 cases[i][1], 어떤 순서로 저장했는지에 따라
        T[i] = cases[i][1];
    }

    vector<int> suffixMax(N);
    suffixMax[N-1] = H[N-1];
    for (int i = N - 2; i >= 0; i--) {
        suffixMax[i] = max(H[i], suffixMax[i+1]);
    }

    for(int i = 0; i < problems; i++) {
        int k = upper_bound(T.begin(), T.end(), outTime[i]) - T.begin();
        cout << suffixMax[k] << endl;
    }
    return 0;
}