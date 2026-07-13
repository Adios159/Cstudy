#include <iostream>
using namespace std;

class Bubble {
    int radius;
public:
    Bubble(int radius) {this->radius = radius;}
    int getRadius() {return radius;}
    void setRadius(int n) {radius = n;}
};

Bubble addBubble(Bubble* c, Bubble* b, Bubble* a) {
    int radA = a->getRadius();
    int radB = b->getRadius();
    int radC = c->getRadius();

    c->setRadius(radA + radB + radC);
    return *c;
}

int main() {
    Bubble a(5), b(10), c(30);
    addBubble(&c, &a, &b);
    cout << "radius of C: " << c.getRadius() << endl;

    return 0;
}