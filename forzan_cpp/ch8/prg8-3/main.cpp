#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ifp;

    const int CAPACITY = 50;
    int numbers[CAPACITY];
    int size = 0, sum = 0;
    double average;
    int smallest = 10000000, largest = -1000000;

    ifp.open("data.txt");
    if(!ifp) {
        cout << "NO FILE" << endl;
        return 1;
    }

    while(ifp >> numbers[size]) {
        size++;
    }
    for(int i = 0; i < size; i++) {
        sum+= numbers[i];
        if(numbers[i] < smallest) {
            smallest = numbers[i];
        }
        if(numbers[i] > largest) {
            largest = numbers[i];
        }

    }
    average = static_cast<double>(sum) / size;
    cout << size << " numbers in array" << endl;
    cout << "sum: " << sum << endl;
    cout << "average: " << average << endl;
    cout << "miniumum: " << smallest << endl;
    cout << "maximum: " << largest << endl;

    return 0;
}