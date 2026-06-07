#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this->kick = kick;
        this->punch = punch;
    }
    void show();
    Power operator+ (Power op2);
    bool operator== (Power op2);
};

void Power::show() {
    cout << "kick: " << kick << "punch: " << punch << endl;
}

Power Power::operator+(Power op2) {
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

bool Power::operator==(Power op2) {
    if(kick == op2.kick && punch == op2.punch)
        return true;
    else    
        return false;
}

int main() {
    Power a(3, 5), b(4, 6), c;
    c = a + b;
    a.show();
    b.show(); c.show();

    if(a == b) 
        cout << "both power are same" << endl;
    else    
        cout << "both power are not same" << endl;

    return 0;
}