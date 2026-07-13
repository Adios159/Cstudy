#include <iostream>
#include <vector>
using namespace std;

int main() {
    int people, mem, whoSend, whoGet;
    cin >> people;

    vector<vector<int>> relation(people, vector<int>(people, 0));
    for(int i = 0; i < people; i++) {
        int k;
        cin >> k; // 보낸 인원 수
        for(int j = 0; j < k; j++) {
            int whoGet;
            cin >> whoGet;
            relation[i][whoGet - 1] = 1; // i번(0-index)이 whoGet번에게 보냄
        }
    }

    for(int i = 0; i < people; i++) {
        vector<int> senders;
        for(int j = 0; j < people; j++) {
            if(relation[j][i] == 1) {  // j가 i에게 보냈는지
                senders.push_back(j + 1);  // 1-index로 변환
            }
        }
        cout << senders.size();
        for(int x : senders) {
            cout << " " << x;
        }
        cout << endl;
    }
    
    return 0;
}
