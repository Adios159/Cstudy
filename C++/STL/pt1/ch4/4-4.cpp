#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Array {
    T *buf;
    int size;
    int capacity;
public:
    explicit Array(int cap = 100) {
        this->size = 0;
        this->capacity = cap;
        buf = new T[capacity];
    }
    ~Array() {
        delete [] buf;
    }
    void Add(T data) {
        buf[size++] = data;
    }
    T operator[] (int idx) {
        return buf[idx];
    }
    const int get_size() {
        return size;
    }
};

int main() {
    Array<int> iarr;
    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);
    
    for(int i = 0; i < iarr.get_size(); i++) {
        cout << iarr[i] << endl;
    }

    return 0;
}