#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, M, K, S;
    int max, min, cnt;
    cin >> N >> M >> K;
    vector<vector<int>> scores;
    for(int i = 0; i < N; i++) {
        vector<int> score;
        for(int j = 0; j < M; j++) {
            cin >> S;
            score.push_back(S);
        }
        scores.push_back(score);
    }

    if(M < 3) {
        vector<int> final_score;
        for(int i = 0; i < N; i++) {
            int invi_score = 0;
            int average = 0;
            for(int j = 0; j < M; j++) {
                invi_score += scores[i][j];
            }
            average = floor(invi_score / M);
            final_score.push_back(average);
        }
        cnt = 0;
        for(unsigned i = 0; i < final_score.size(); i++) {
            if(final_score[i] >= K) {
                cnt++;
            }
        }
        cout << final_score.size() - cnt << endl;
        return 0;
    }
    
    vector<int> final_score;
    for(int i = 0; i < N; i++) {
        int invi_score = 0;
        int average = 0;
        max = scores[i][0];
        min = scores[i][0];
        for(int j = 0; j < M; j++) {
            invi_score += scores[i][j];
            if(max < scores[i][j]) {
                max = scores[i][j];
            }
            if(min > scores[i][j]) {
                min = scores[i][j];
            }
        }
        invi_score -= max + min;
        average = floor(invi_score / (M - 2));
        final_score.push_back(average);
    }
    cnt = 0;
    for(unsigned i = 0; i < final_score.size(); i++) {
        if(final_score[i] >= K) {
            cnt++;
        }
    }
    cout << final_score.size() - cnt << endl;
    return 0;
}