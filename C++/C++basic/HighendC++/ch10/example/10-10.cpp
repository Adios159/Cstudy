#include <iostream>
#include <string>
#include <map>
using namespace std;

class Item {
    public:
        int price, count;
        Item(int price = 0, int count = 0) {
            this->count = count;
            this->price = price;
        }
};

int main() {
    map<string, Item> stock;
    string name;
    int price = 0, count = 0, removedCount = 0;

    while(true) {
        cout << "put stock:1, delete:2, search:3, exit:4 >> ";
        int cmd;
        cin >> cmd;
        switch(cmd) {
            case 1:
                cout << "name, price, count: ";
                cin >> name >> price >> count;
                stock.insert(make_pair(name, Item(price, count)));
                break;
            case 2:
                cout << "inpute name: ";
                cin >> name;
                removedCount = stock.erase(name);
                if(removedCount == 0)
                    cout << "delete failed" << endl;
                else    
                    cout << "deleted" << endl;
                break;
            case 3:
                cout << "inpute name: ";
                cin >> name;
                if(stock.find(name) == stock.end())
                    cout << "we don't have" << name << endl;
                else {
                    Item item = stock[name];
                    cout << "price: " << item.price << ", stock: " << count << endl;
                }
            case 4:
                return 0;
        }
    }
}