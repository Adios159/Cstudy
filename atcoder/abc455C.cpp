#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<int, long long> sum;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum[a] += a;
    }

    // 여기서부터 이어서 짜봐
}