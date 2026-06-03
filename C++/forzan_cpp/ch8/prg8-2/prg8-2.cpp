#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int CAPACITY = 50;
    int numbers[CAPACITY];
    int size = 0;
    ifstream ifp;
    ofstream ofp;

    ifp.open("data.txt");
    if(!ifp) {
        cout << "No FILE!" << endl;
        return 1;
    }
    while(ifp >> numbers[size] && size <= 50) {
        size ++;
    }
    ifp.close();

    ofp.open("write.txt");
    if(!ofp) {
        cout << "No FILE!" << endl;
        return 1;
    }
    for(int i = size - 1; i >= 0; i--) {
        ofp   << numbers[i] << " ";
    }
    ofp.close();

    return 0;
}