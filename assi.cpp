#include <iostream>
#include <string>
using namespace std;



int main() {
    int tCase, p, q, r, s, w;
    int Acase = 0, Bcase = 0;
    cin >> tCase;


    for(int i = 0; i < tCase; i++) {
        Acase = 0, Bcase = 0;
        cin >> p >> q >> r >> s >> w;
        Acase += p * w;
        if(w < r) {
            Bcase += q;
        }
        else {
            Bcase += q + ((w - r) * s);
        }

        if(Acase > Bcase) {
            cout << '#' << i << ' ' << Bcase << endl;
        }
        else {
            cout << '#' << i << ' ' << Acase << endl;
        }
    }

    return 0;
}