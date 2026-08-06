#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, cnt = 0;
    string ans = "Yes";
    cin >> N;
    int j = 2;
    for(int i = 1; i <= N; i++) {
        if(j <= i) {
            j = i + 1;
        }
        ans = "Yes";
        while(j <= N) {
            cout << '?' << ' ' << i << ' ' << j << endl;
            cin >> ans;
            if (ans == "Yes") {
                j++;
            }
            else {
                break;
            }
        }
        cnt += j - i - 1;
    }
    cout << '!' << ' ' << cnt << endl;
    return 0;
}