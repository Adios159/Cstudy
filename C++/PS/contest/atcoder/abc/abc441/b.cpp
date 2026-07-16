#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<char> S, T;
    string s, t;
    cin >> s >> t;

    for (char c : s) S.insert(c);
    for (char c : t) T.insert(c);
    int Q;
    string W;
    cin >> Q;
    for(int i = 0; i < Q;  i++) {
        cin >> W;
        bool is_taka = true;
        bool is_aoki = true;
        for(int j = 0; j < W.size(); j++) {
            if(!(S.contains(W[j]))) {
                is_taka = false;
            }
            if(!(T.contains(W[j]))) {
                is_aoki = false;
            }
        }
        if(is_taka == true && is_aoki == true)  {
            cout << "Unknown" << endl;
        }

        else if(is_taka == true && is_aoki == false) {
            cout << "Takahashi" << endl;
        }

        else  {
            cout << "Aoki" << endl;
        }
    }
    return 0;
}