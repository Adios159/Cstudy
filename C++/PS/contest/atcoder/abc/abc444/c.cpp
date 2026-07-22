#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long N, K;
    vector<long> stick;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> K;
        stick.push_back(K);
    }
    sort(stick.begin(), stick.end());
    long l1 = stick[stick.size() - 1];
    long l2 = stick[0] + stick[stick.size() - 1];
    long lo = 0;
    long hi = stick.size() - 1;
    bool l1_success = false;
    bool l2_success = false;
    while(lo <= hi) {
        if(lo == hi) {
            if(stick[hi] == l1) {
                l1_success = true;
                --hi;
                continue;
            }
            else if(stick[hi] < l1) {
                l1_success = false;
                break;
            }
        }
        if(stick[hi] == l1) {
            --hi;
            l1_success = true;
            continue;
        }
        if(stick[hi] < l1) {
            if(stick[lo] + stick[hi] == l1) {
                lo++;
                --hi;
                l1_success = true;
                continue;
            }
            else {
                l1_success = false;
                break;
            }
        }
        
    }
    lo = 0;
    hi = stick.size() - 1;
    while(lo <= hi) {
        if(lo == hi) {
            if(stick[hi] == l2) {
                l2_success = true;
                --hi;
                continue;
            }
            else if(stick[hi] < l2) {
                l2_success = false;
                break;
            }
        }
        if(stick[hi] == l2) {
            --hi;
            l2_success = true;
            continue;
        }
        if(stick[hi] < l2) {
            if(stick[lo] + stick[hi] == l2) {
                lo++;
                --hi;
                l2_success = true;
                continue;
            }
            else {
                l2_success = false;
                break;
            }
        }
        
    }
    if(l1_success) {
        cout << l1 << ' ';
    }
    if(l2_success) {
        cout << l2;
    }
    cout << '\n';
    return 0;
}