#include <iostream>
#include <string>
using namespace std;

class Espresso {
    protected:
        string name;
        int espresso, water;
    public:
        Espresso(string name, int espresso, int water) {
            this->name = name;
            this->espresso = espresso;
            this->water = water;
        }
        void showRecipe() {
            cout << "name: " << name << endl;
            cout << "espresso: " << espresso << "shots" << endl;
            cout << "water: " << water << "cups" << endl;
        }
        void getRecipe(string& name, int& espresso, int&water) {
            name = this->name;
            espresso = this->espresso;
            water = this->water;
        }
};

class Cappuccino : public Espresso {
    private:
        int milk;
        bool iceIn;
    public:
        Cappuccino(string name, int espresso, int water, int milk, bool iceIn) : Espresso(name, espresso, water) {
            this->milk = milk;
            this->iceIn = iceIn;
        }
        void showRecipe() {
            cout << "name: " << name << endl;
            cout << "espresso: " << espresso << "shots" << endl;
            cout << "water: " << water << "cups" << endl;
            cout << "milk: " << milk << "cups" << endl;
            if(iceIn == true)
                cout << "put ice a lot" << endl;
            else
                cout << "no ice in here" << endl;
        }
};

int main() {
    Espresso espresso("espresso", 3, 0);
    Espresso americano("americano", 2, 5);
    americano.showRecipe();
    cout << endl;

    Cappuccino HotCapu("hot cappuccino", 2, 2, 4, false);
    HotCapu.showRecipe();
    cout << endl;
    
    Cappuccino IcedCapu("iced cappuccino", 2, 1, 5, true);
    IcedCapu.showRecipe();

    return 0;
}