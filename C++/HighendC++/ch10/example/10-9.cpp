#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, string> dic;
    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));
    dic.insert(make_pair("paper", "종이"));
    dic["cherry"] = "체리";

    cout << "dictnary size: " << dic.size() << endl;
    string eng;
    while(true) {
        cout << "word to find: ";
        getline(cin, eng);
        if(eng == "exit")
            break;
        if(dic.find(eng) == dic.end())
            cout << "No word in dic" << endl;
        else    
            cout << dic[eng] << endl;
    }
    cout << "shutdown" << endl;
    return 0;
}