#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> server(N);
    for(int i = 0; i < N; i++) {
        cin >> server[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (server[i][j] != '#') 
                continue; // 서버가 있는 칸만 검사
            int count = 0;
            if (i > 0 && server[i-1][j] == '#') 
                count++;
            if (i < N - 1 && server[i+1][j] == '#') 
                count++;
            if (j > 0 && server[i][j - 1] == '#') 
                count++;
            if (j < M - 1 && server[i][j + 1] == '#') 
                count++;
            
            if (count < 1 || count > 3) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}