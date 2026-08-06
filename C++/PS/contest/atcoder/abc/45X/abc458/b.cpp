#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    if(H == 1 && W == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int count = 4;
            if (i == 0) 
                count--;  
            if (i == H-1) 
                count--;    
            if (j == 0) 
                count--;      
            if (j == W-1) 
                count--;    
            cout << count << ' ';
        }
        cout << endl;
    }
    return 0;
}