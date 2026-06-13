#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long monster, monsterGold, monsterAttack, playerAttack = 0, playerGold = 0; 
    stack<pair<long long,long long>> monsterStack;
    cin >> monster;


    for(int i = 0; i < monster; i++) {
        cin >> monsterAttack >> monsterGold;
        if(playerAttack >= monsterAttack) {
            playerAttack += monsterAttack;
            playerGold += monsterGold;
        }
        else {
            monsterStack.push({monsterAttack, monsterGold});
        }

        while(!monsterStack.empty() && playerAttack >= monsterStack.top().first) {
            playerAttack += monsterStack.top().first;
            playerGold += monsterStack.top().second;
            monsterStack.pop();
        }
    }

    cout << playerGold << endl;
    return 0;
}