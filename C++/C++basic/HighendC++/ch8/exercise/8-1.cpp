#include <iostream>
#include <string>
using namespace std;

class Circle{
    protected:
        int radius;
    public:
        Circle(int radius) { this->radius = radius; };
        double getArea() { return 3.14 * radius * radius; }
        int getRadius() { return radius; }
        void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle : public Circle {
    private:
        string name;
    public:
        NamedCircle(int radius, string name) : Circle(radius) {
            this->name = name;
        }
        void show() {
            cout << "radius: " << radius << " name: " << name << endl;
        }
};

int main() {
    NamedCircle waffle(3, "waffle");
    waffle.show();

    return 0;
}