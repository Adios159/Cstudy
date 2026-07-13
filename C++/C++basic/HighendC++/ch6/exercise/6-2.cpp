#include <iostream>
using namespace std;

void print_matrix(int col = 2, int row = 2) {
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            cout << '*';
        }
        cout << endl;
    }
}

void print_matrix(int col, int row, char ch) {
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            cout << ch;
        }
        cout << endl;
    }
}

int main() {
    print_matrix();
    print_matrix(2, 5, 'a');
    print_matrix(1, 10);

    return 0;
}