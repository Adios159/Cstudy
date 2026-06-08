#include <iostream>
using namespace std;

class Color {
    int r, g, b;
public:
    Color(int r, int g, int b);
    void printColor(Color *c);
};

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Color::printColor(Color *c) {
    cout << "R: " << c->r
         << " G: " << c->g
         << " B: " << c->b << endl;
}

int main() {
    Color fore(255, 0, 0), back(15, 128, 200);
    fore.printColor(&fore);
    fore.printColor(&back);

    return 0;
}