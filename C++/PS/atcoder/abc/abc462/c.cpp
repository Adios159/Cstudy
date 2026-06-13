#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int,int>> points(n); // {X, Y}
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // X 기준 오름차순 정렬
    sort(points.begin(), points.end());

    int ans = 0;
    int min_y = INT_MAX;

    for (int i = 0; i < n; i++) {
        int y = points[i].second;

        // 이전 점들의 Y 최솟값이 현재 Y 이상이면 내부에 점 없음
        if (min_y >= y) {
            ans++;
        }

        // 최솟값 갱신
        min_y = min(min_y, y);
    }

    cout << ans << endl;
    return 0;
}