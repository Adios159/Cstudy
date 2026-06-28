#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int bird, date;
    cin >> bird >> date;
    vector<vector<int>> arr;
    vector<int> color;
    vector<int> bird_color(3);
    for(int i = 0; i < bird; i++) {
        bird_color = {0, 0, 0};
        cin >> bird_color[0] >> bird_color[1] >> bird_color[2];
        arr.push_back(bird_color);
    }
    for(int i = 1; i <= date; i++) {
        color = {};
        for(int j = 0; j < bird; j++) {
            vector<int> tmp = arr[j];
            if(tmp[1] > i) {
                color.push_back(tmp[0]);
            }
            else {
                color.push_back(tmp[2]);
            }
        }
        sort(color.begin(), color.end()); 
        color.erase(unique(color.begin(), color.end()), color.end());  
        cout << color.size() << endl;
    }

    return 0;
}