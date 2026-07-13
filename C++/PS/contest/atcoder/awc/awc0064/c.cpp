#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, time, score;
    cin >> N >> M;
    vector<pair<long long, int>> homework;
    vector<long long> dp(M + 1, 0);
    for(int i = 0; i < N; i++) {
        cin >> score >> time;
        homework.push_back(make_pair(score, time));
    }

    for (int i = 0; i < N; i++) {          // 바깥: 숙제 하나씩
        for (int j = M; j >= homework[i].second; j--) {  // 안쪽: j는 반드시 감소 방향!
            dp[j] = max(dp[j], dp[j - homework[i].second] + homework[i].first);
        }
    }
    
    cout << dp[M] << endl;
    return 0;
}