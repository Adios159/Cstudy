#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string S, T;
    int ans = 0, s_cnt = 0, t_cnt = 0, s_total = 0, t_total = 0;
    cin >> S;
    cin >> T;
    if(S == T) {
        cout << 0 << '\n';
        return 0;
    }
    string s_temp = S;
    string t_temp = T;
    s_temp.erase(remove(s_temp.begin(), s_temp.end(), 'A'), s_temp.end());
    t_temp.erase(remove(t_temp.begin(), t_temp.end(), 'A'), t_temp.end());
    if(s_temp != t_temp) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> s_char;
    vector<int> t_char;

    for(char c: S) {
        if(c == 'A') 
            s_cnt++;
        else {
            s_char.push_back(s_cnt);
            s_cnt = 0;
        }
    }
    s_char.push_back(s_cnt);
    for(char c: T) {
        if(c == 'A') 
            t_cnt++;
        else {
            t_char.push_back(t_cnt);
            t_cnt = 0;
        }
    }
    t_char.push_back(t_cnt);

    for(int i = 0; i < s_char.size(); i++)
        ans += abs(s_char[i] - t_char[i]);
    
    cout <<  ans << '\n';
    return 0;
}