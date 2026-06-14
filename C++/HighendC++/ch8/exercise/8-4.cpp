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

class Point3D : public Point {
    private:
        int z;
    public:
        Point3D(int x, int y, int z) : Point(x, y) {
            this->z = z;
        }
        void set(int x, int y, int z) {
            move(x, y);
            this->z = z;
        }
        void upZ() { this->z += 1; }
        void goRight() { move(getX() + 1, getY()); }
        void goUp() { move(getX(), getY() + 1); }
        void show() {
            cout << "(" << getX() << "," << getY() << "," << z << ")" << endl;
        }
};

int main() {
    Point3D p(1, 2, 3);
    p.show();
    p.upZ();
    p.goRight();
    p.goUp();
    p.show();
    p.set(10, 20, 30);
    p.show();

    return 0;
}