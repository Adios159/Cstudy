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
    Coffee operator+(Coffee c2);
    Coffee operator+(int shot);
};

Coffee Coffee::operator+(Coffee c2) {
        return Coffee
        (this->water + c2.water,
         this->espresso + c2.espresso,
         this->sugar + c2.sugar,
         this->cream + c2.cream);
}

Coffee Coffee::operator+(int shot) {
    return Coffee(
        this->water,
        this->espresso + shot,
        this->sugar,
        this->cream
    );
}
int main() {
    Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
    c = black + dabang;
    d = c + 1;
    c.show();
    d.show();

    return 0;
}