    #include <iostream>
    #include <vector>
    #include <numeric> 
    #include <algorithm>
    using namespace std;
    int main() {
        long long N, M, L, R, A;
        long long farm[300001];
        vector<long long> manufact;
        cin >> N >> M;

        for(long long i = 0; i < N; i++) {
            cin >> A;
            farm[i] = A;
        }

        for(long long i = 0; i < M; i++) {
            long long sum = 0, start = 0, end = 0;
            cin >> L >> R;
            start = L - 1;
            end = R;
            sum = accumulate(farm + start, farm + end, 0LL);
            manufact.push_back(sum);
        }
        sort(manufact.rbegin(), manufact.rend());
        cout << manufact[0] - manufact[manufact.size() - 1] << endl;
        return 0;
    }