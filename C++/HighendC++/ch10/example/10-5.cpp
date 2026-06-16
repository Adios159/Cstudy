#include <iostream>
using namespace std;

template <class T>
class MyStack {
    private:
        int top;
        T data[100];
    public:
        MyStack();
        void push(T element);
        T pop();
};

template <class T>
MyStack<T>::MyStack() {
    top = -1;
}

template <class T>
void MyStack<T>::push(T element) {
    if(top == 99) {
        cout << "stack overflow" << endl;
        return;
    }
    top++;
    data[top] = element;
}

template <class T>
T MyStack<T>::pop() {
    T retData;
    if(top == -1) {
        cout << "stack underflow" << endl;
        return retData;  // ✅ Fix 1
    }
    retData = data[top--];
    return retData;
}

int main() {  // ✅ Fix 2
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << endl;

    MyStack<float> fStack;
    fStack.push(3.1);
    cout << fStack.pop() << endl;

    return 0;
}