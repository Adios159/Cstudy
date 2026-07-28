#include <bits/stdc++.h>
using namespace std;

// ---------- 타입 별칭 ----------
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// ---------- 매크로 ----------
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// ---------- 상수 ----------
const int INF = 1e9;
const ll LLINF = 4e18;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979;

char field[1001][1001];
int H, W, length = 0, max_len = 0;
bool visited[1005][1005] = {false};

bool isValid(int x, int y) {
    if(x < 0 || x >= H || y < 0 || y >= W) return false;
    if(field[x][y] != '.') return false;
    if(visited[x][y]) return false;
    return true;
}


int main() {
    fastio;
    
    cin >> H >> W;
    vpii land;
    char c;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> field[i][j];
            if(field[i][j] == '.') {
                land.push_back(make_pair(i, j));
            }
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pii> q;
    // 테두리 칸들 중 흰 칸을 큐에 삽입 + visited 처리
    for(int j = 0; j < W; j++) {
        // (0, j)와 (H-1, j) 처리
        if(field[0][j] == '.') {
            q.push(make_pair(0, j));
            visited[0][j] = true;
        }
        if(field[H - 1][j] == '.') {
            q.push(make_pair(H - 1, j));
            visited[H - 1][j] = true;
        }
    }
    for(int i = 0; i < H; i++) {
        // (i, 0)와 (i, W-1) 처리
        if(field[i][0] == '.') {
            q.push(make_pair(i, 0));
            visited[i][0] = true;
        }
        if(field[i][W-1] == '.') {
            q.push(make_pair(i, W-1));
            visited[i][W-1] = true;
        }
    }

    // BFS 돌리기
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            // 범위 체크, 흰 칸인지 체크, visited 체크 후
            // visited 처리하고 큐에 삽입
            if(isValid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(field[i][j] == '.' && visited[i][j] == false) {
                answer++;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        // 범위 체크, 흰 칸인지 체크, visited 체크 후
                        // visited 처리하고 큐에 삽입
                        if(isValid(nx, ny)) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}