#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    if (!(cin >> H >> W)) return 0;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int min_r = H, max_r = -1;
    int min_c = W, max_c = -1;

    // Find the bounding box
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (grid[r][c] == '#') {
                min_r = min(min_r, r);
                max_r = max(max_r, r);
                min_c = min(min_c, c);
                max_c = max(max_c, c);
            }
        }
    }

    // Print the cropped image
    for (int r = min_r; r <= max_r; ++r) {
        cout << grid[r].substr(min_c, max_c - min_c + 1) << "\n";
    }

    return 0;
}