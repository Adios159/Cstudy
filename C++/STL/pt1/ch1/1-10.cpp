#include <iostream>
using namespace std;

class Array {
    int *arr;
    int size;
    int capacity;
public:
    Array(int cap = 100) : arr(0), size(0), capacity(cap) {
        arr = new int[capacity];
    }
    ~Array() {
        delete [] arr;
    }
    void add(int data) {
        if(size < capacity)
            arr[size++] = data;
    }
    int Size() const {
        return size;
    }
    int operator[] (int idx) const {
        return arr[idx];
    }
    int& operator[] (int idx) {
        return arr[idx];
    }
};

int main() {
    Array arr(10);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

    const Array& arr2 = arr;
    cout << arr2[0] << endl;
    arr[0] = 100;
    // arr2[0] = 100;

    return 0;
}