#include <iostream>
using namespace std;

int main() {
    int dice[3][6];
    int count[3][3] = {0};
    double prop;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            if(dice[i][j] == 4) {
                count[i][0]++;
            }
            else if(dice[i][j] == 5) {
                count[i][1]++;
            }
            else if(dice[i][j] == 6) {
                count[i][2]++;
            }
            else 
                continue;
        }
    }

    prop = (1.0 / 216.0) * ((count[0][0] * count[1][1] * count[2][2]) + (count[0][0] * count[1][2] * count[2][1])
+ (count[0][1] * count[1][0] * count[2][2]) + (count[0][1] * count[1][2] * count[2][0]) 
+ (count[0][2] * count[1][1] * count[2][0]) + (count[0][2] * count[1][0] * count[2][1]));
    cout << prop << endl;

    return 0;
}