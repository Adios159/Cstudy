#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len;
    cin >> len;
    vector<vector<int>> A(len);

    for (int i = 0; i < len; i++) {
        int l;
        cin >> l;
        A[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> A[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    cout << A[x - 1][y - 1] << endl;

    return 0;
}