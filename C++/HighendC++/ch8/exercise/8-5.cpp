#include <iostream>
#include <string>
using namespace std;

class Member {
    protected:
        string name;
        int point = 0;
        float ratio;
    public:
        Member(string name, float ratio = 0.01) {
            this->name = name;
            this->ratio = ratio;
        }
        int earn(int pay) {
            point += pay * ratio;
            return point;
        }
        int getpoint() {return point;}
        void show() {
            cout << name << "'s point: " << point << endl;
        }
};

class GoldMember : public Member {
    public:
        GoldMember(string name, float ratio = 0.03) : Member(name, ratio) {}
        float setRatio(int pay) {
            if(pay < 10000) 
                this->ratio = 0.03;
            else if(pay >= 10000 && pay < 20000) 
                this->ratio = 0.04;
            else
                this->ratio = 0.05;
            return ratio;
        } 
        int earn(int pay) {
            setRatio(pay);
            point += pay * ratio;
            return point;
        }
};

int main() {
    Member a("Hwang");
    GoldMember b("Kim");
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << "name and paid money: ";
        string name; int pay;
        cin >> name >> pay;
        if (name == "Hwang") a.earn(pay);
        else if(name == "Kim") b.earn(pay);
        else i--;
    }
    a.show(); b.show();
    return 0;
}