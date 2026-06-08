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
};

int main() {
    Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
}