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
    Coffee& operator<<(Coffee c) {
        this->water    += c.water;
        this->espresso += c.espresso;
        this->sugar    += c.sugar;
        this->cream    += c.cream;
        return *this;
    }

    Coffee& operator<<(int moreW) {
        this->water += moreW;
        return *this;
    }
};

int main() {
    Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2);
    black << dabang << 3;
    black.show();

    return 0;
}