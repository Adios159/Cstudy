#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0;  i < N; i++) {
        int px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        if(((qy - py) * (sx - rx)) == ((sy - ry) * (qx - px))) {
            if(((ry - py) * (sx - qx)) == ((sy - qy) * (rx - px))) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}