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
    Coffee& operator+=(Coffee c);
    Coffee& operator+=(int shot);
    Coffee& operator++();
};

Coffee& Coffee::operator+=(Coffee c) {
    this->water    += c.water;
    this->espresso += c.espresso;
    this->sugar    += c.sugar;
    this->cream    += c.cream;
    return *this;  // 자기 자신 반환
}

Coffee& Coffee::operator+=(int shot) {
    this->espresso += shot;
    return *this;
}

Coffee& Coffee::operator++() {  // 전위 ++
    this->espresso += 1;
    return *this;
}

int main() {
    Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
    black += dabang;
    black += 1;
    ++black;
    black.show();

    return 0;
}