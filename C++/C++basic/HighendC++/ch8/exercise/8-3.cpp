#include <iostream>
#include <string>
using namespace std;

class Point {
    private:
        int x, y;
    protected:
        void move(int x, int y) {
            this->x = x;
            this->y = y;
        }
    public:
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        int getX() { return x; }
        int getY() { return y; }
};

class ColorPoint : public Point {
    private:
        string color;
    public:
        ColorPoint(int x, int y, string color) : Point(x, y) {
            this->color = color;
        }
        void setColor(string color) { this->color = color; }
        void setPoint(int x, int y) {
            move(x, y);
        }
        void show() {
            cout << color << ": ";
            cout << "(" << getX() << "," << getY() << ")" << endl;
        }
};

int main() {
    ColorPoint cp(5, 5, "Red");
    cp.setPoint(30, 40);
    cp.setColor("Blue");
    cp.show();

    return 0;
}