#include <iostream>
#include <string>
using namespace std;

class gameBoard {
    int blueSc, whiteSc;
    string team;
public:
    gameBoard() {
        this->blueSc = 0;
        this->whiteSc = 0;
    }
    gameBoard increase() {
        this->blueSc += 10;
        this->whiteSc += 10;
        return *this;
    }
    gameBoard increase(int score) {
        this->blueSc += score;
        this->whiteSc += score;
        return *this;
    }

    gameBoard increase(int score, string team) {
        if(team == "blue") {
            this->blueSc += score;
            return *this;
        }
        else if(team == "white") {
            this->whiteSc += score;
            return *this;
        }
        else    
            exit(1);
    }
    void show() {
        cout << "blue team: " << this->blueSc << " white team: " << this->whiteSc << endl;
    }
};

int main() {
    gameBoard board;
    board.increase();
    board.increase(20);
    board.increase(30, "blue");
    board.increase(40, "white");

    board.show();

    return 0;
}