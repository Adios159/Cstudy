#include <iostream>
#include <string>
using namespace std;

class Wallet {
    string name;
    int money;
public:
    Wallet(string name, int money = 0) {
        this->name = name;
        this->money = money;
    }

    void show() {
        cout << name << "'s wallet has " << money << " won" << endl;
    }

    Wallet& operator+=(int income) {
        this->money += income;
        return *this;
    }

    Wallet& operator-=(int out) {
        this->money -= out;
        return *this;
    }

    Wallet operator+(const Wallet& w) {
        return Wallet(this->name, this->money + w.money);
    }

    Wallet operator+(int income) {
        return Wallet(this->name, this->money + income);
    }

    friend Wallet operator+(int income, const Wallet& w) {
        return Wallet(w.name, w.money + income);
    }

    Wallet& operator=(int money) {
        this->money = money;
        return *this;
    }
};

int main() {
    Wallet a("kim", 2000), b("Lee", 100), c("Park");
    a += 1000; a.show();   // kim's wallet has 3000 won
    a -= 500;  a.show();   // kim's wallet has 2500 won
    b = a + b + 100;
    b.show();              // Lee's wallet has 2700 won
    c = 500 + b;
    c.show();              // Park's wallet has 3200 won
}