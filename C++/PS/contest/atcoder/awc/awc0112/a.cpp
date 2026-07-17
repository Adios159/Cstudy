#include <iostream>
using namespace std;

int main() {
    int N, K, A;
    int streak = 0, streak_save = 0;
    cin >> N  >> K;
    for(int i = 0;  i < N; i++) {
        cin >> A;
        if(A >= K) {
            streak++;
            if(streak > streak_save) {
                streak_save = streak;
            }
        }
        else {
            if(streak > streak_save) {
                streak_save = streak;
            }
            streak = 0;
        }
    }
    cout << streak_save << endl;
    return 0;
}