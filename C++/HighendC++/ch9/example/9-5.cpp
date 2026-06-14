#include <iostream>
using namespace std;

class Base {
    public:
        virtual ~Base() { cout << "Base deleted" << endl; }
};
class Derived : public Base {
    public:
        virtual ~Derived() {cout << "Derived deleted" << endl;} 
};

int main() {
    Derived *dp = new Derived();
    Base *bp = new Derived();

    delete dp;
    delete bp;

    return 0;
}