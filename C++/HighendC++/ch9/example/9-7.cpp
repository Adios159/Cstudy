#include <iostream>
using namespace std;

class Calculator {
    private:
        void input() {
            cout << "input 2 numbers: ";
            cin >> a >> b;
        }
    protected:
        int a, b;
        virtual int calc(int a, int b) = 0;
    public:
        void run() {
            input();
            cout << "result: " << calc(a, b) << endl;
        }
}; 

class Adder : public Calculator {
    protected:
        int calc(int a, int b) {
            return a + b;
        }
};

class Subtractor : public Calculator {
    protected:
        int calc(int a, int b) {
            return a- b;
        }
};

int main() {
    Adder adder;
    Subtractor subtractor;

    adder.run();
    subtractor.run();
    return 0;
}