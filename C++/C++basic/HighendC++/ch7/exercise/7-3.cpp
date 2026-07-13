#include <iostream>
using namespace std;

class Coffee {
    int water, espresso, sugar, cream;
public:
    Coffee(int water = 1, int espresso = 1, 
           int sugar = 0, int cream =0) {
        this->water = water;
        this->espresso = espresso;
        this->sugar = sugar;
        this->cream = cream;
    }
    void show() {
        cout << "water: " << water << ", coffee: " << espresso;
        cout << ", sugar: " << sugar << ", cream: " << cream << endl;
    }
    bool operator!() {
        if(this->sugar == 0) {
            return true;
        }
        else return false;
    }

    bool operator>(Coffee c) {
        int sum1 = this->water + this->espresso + this->sugar + this->cream;
        int sum2 = c.water + c.espresso + c.sugar + c.cream;
        if (sum1 > sum2) return true;
        else return false;
    }
};


int main() {
    Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
    if(!a)
        cout << "No sugar!" << endl;
    if(a > b) cout << "a has much coffee" << endl;
    else cout << "b has much coffee" << endl;
}