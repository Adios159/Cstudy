#include <iostream>
#include <vector>
using namespace std;

int square_sum(int n) {
    int sum = 0;
    while(true) {
        if(n / 10 == 0) {
            sum += n * n;
            return sum;
        }
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }
}

int main() {
    int N, next_val = 0, curr = 0;
    vector<bool> is_visited(2026);
    cin >> N;
    curr = N;
    while(true) {
        next_val = square_sum(curr);
        if(next_val == 1) {
            cout << "Yes\n";
            return 0;
        }
        else {
            if(is_visited[next_val] == true) {
                cout << "No\n";
                return 0;
            }
            else {
                is_visited[next_val] = true;
            }
        }
        curr = next_val;
    }
}