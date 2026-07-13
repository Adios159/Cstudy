    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int main() {
        int buliding, idx;
        cin >> buliding >> idx;

        vector<long long> locations;
        long long location;
        for(int i = 0; i < buliding; i++) {
            cin >> location;
            locations.push_back(location);
        }

        cout << locations[idx - 1] - 1 << endl;

        return 0;
    }