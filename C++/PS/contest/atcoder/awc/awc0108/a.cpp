#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, location = 0;
    double strange = 0, mean = 0;
    vector<int> temperature;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        temperature.push_back(temp);
        mean += temperature[i];
    }
    mean /= temperature.size();
    strange =abs(mean - temperature[0]);

    for(int i = 0; i < temperature.size(); i++) {
        if(strange < abs(mean - temperature[i])) {
            strange = abs(mean - temperature[i]);
            location = i;
        }
    }
    cout << location + 1 << endl;
    return 0;
}