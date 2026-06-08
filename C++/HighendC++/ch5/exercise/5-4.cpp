#include <iostream>
using namespace std;

class Bubble {
    int radius;
public:
    Bubble(int radius) {this->radius = radius;}
    int getRadius() {return radius;}
    void setRadius(int n) {radius = n;}
};

bool combineBubble(Bubble *a, Bubble *b) {
    int radA = a->getRadius();
    int radB = b->getRadius();

    if(radA > radB) {
        a->setRadius(radA + radB);
        b->setRadius(0);
        return true;
    }

    else if(radA == radB) {
        return false;
    }

    else {
        b->setRadius(radA + radB);
        a->setRadius(0);
        return true;
    }
}

int main() {
    Bubble a(5), b(10);
    if(combineBubble(&a, &b) == false)
        cout << "both bubble`s radius are same" << endl;
    else {
        cout << "merge to big one" << endl;
        cout << "radius of a: " << a.getRadius() << endl;
        cout << "radius of b: " << b.getRadius() << endl;
    }

    return 0;
}