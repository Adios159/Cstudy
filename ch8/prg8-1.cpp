#include <iostream>
using namespace std;

int main() {
    const int CAPACITY = 10;
    int numbers[CAPACITY];
    int size;

    do{
        cout << "Enter size: ";;
        cin >> size;
    } while(size < 1 || size > CAPACITY);

    cout << size << "input numbers: ";
    for(int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    for(int i = size - 1; i >= 0; i--) {
    cout << numbers[i] << endl;
    }

    return 0;
}