#include <iostream>
#include <string>
using namespace std;

int main() {
  int i = 0, length;
  string str;
  cin >> length;
  cin >> str;
  
  while (i < str.length() && str[i] == 'o')
    i++;
  cout << str.substr(i);
}