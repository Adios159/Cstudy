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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bread {
    long long P, T, F;
};

struct Job {
    long long D, T;
    bool operator<(const Job& other) const {
        return D < other.D;
    }
};

int N;
vector<Bread> breads;
vector<Job> jobs;

// 제출 시각 S가 유효한지 검사하는 함수
bool check(long long S) {
    for (int i = 0; i < N; ++i) {
        jobs[i].D = min(breads[i].F + breads[i].T, S - breads[i].P);
        jobs[i].T = breads[i].T;
    }
    
    // 마감 기한(D) 기준 오름차순 정렬 (EDF)
    sort(jobs.begin(), jobs.end());
    
    long long cur_time = 0;
    for (int i = 0; i < N; ++i) {
        cur_time += jobs[i].T;
        if (cur_time > jobs[i].D) {
            return false;
        }
    }
    return true;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> N)) return 0;
    
    breads.resize(N);
    jobs.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> breads[i].P >> breads[i].T >> breads[i].F;
    }
    
    long long low = 0, high = 4000000000LL;
    
    // 무한히 큰 S(4e9)에서도 불가능하다면 절대 불가능함
    if (!check(high)) {
        cout << -1 << "\n";
        return 0;
    }
    
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1; // 더 빠른 시각이 가능한지 탐색
        } else {
            low = mid + 1;  // 시각을 뒤로 미룸
        }
    }
    
    cout << ans << "\n";
    return 0;
}