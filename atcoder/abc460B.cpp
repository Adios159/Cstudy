#include <iostream>
using namespace std;

int main() {
    long long tCase, xPos1, yPos1, rad1, xPos2, yPos2, rad2;
    cin >> tCase;
    long long distPow, sumRad, diffRad, dx, dy; 

    for(int i = 0; i < tCase; i++) {
        cin >> xPos1 >> yPos1 >> rad1 >> xPos2 >> yPos2 >> rad2;
        dx = xPos2 - xPos1;
        dy = yPos2 - yPos1;
        distPow = (dx * dx) + (dy * dy);
        sumRad = (rad1 + rad2) * (rad1 + rad2);
        diffRad = (rad2 - rad1) * (rad2 - rad1);

        if(distPow >= diffRad && sumRad >= distPow) {
            cout << "Yes" << endl;
        } 
        else {
            cout << "No" << endl;
        }
        dx = 0; dy = 0;
    }

    return 0;
}