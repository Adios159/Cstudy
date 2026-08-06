#include <iostream>
#include <vector>
using namespace std;

long long combination3(long long a) {
    long long divide = 1;
    for(int i = 0; i < 3; i++) {
        divide *= a;
        --a;
    }  
    return divide / 6;
}

int main() {
    long long N, M, A, B;
    cin >> N >> M;
    vector<long long> degree(N);
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        degree[A - 1]++;
        degree[B - 1]++;
    }
    for(int i = 0; i <  degree.size(); i++) {
        degree[i] = combination3((N - 1) - (degree[i]));
        cout << degree[i] << ' ';
    }
    cout << '\n';
    return 0;
}