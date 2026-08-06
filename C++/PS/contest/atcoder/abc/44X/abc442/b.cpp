#include <iostream>
using namespace std;

int main() {
    int Q, menu;
    int volume = 0;
    bool is_playing = false;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> menu;
        switch(menu) {
            case 1:
                volume++;
                break;
            case 2:
                if(volume >= 1) {
                    volume--;
                }
                break;
            case 3:
                is_playing = !is_playing;
                break;
        }
        if((is_playing == true) && volume >= 3) {
            cout << "Yes" << endl;
        } 
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}