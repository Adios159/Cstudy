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

    int main() {
        fastio;
        ll N, K, ans = 0;
        vl nums;
        cin >> N >> K;
        ll num;
        for(int i = 0; i < N; i++) {
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());
        vi mods;
        for(int i = 0; i < N; i++) {
            mods.push_back(nums[i] % K);
        }
        sort(mods.begin(), mods.end());
        int min = mods[0];
        int max = mods[nums.size() - 1];
        int diff = max - min;

        for(int i = 0; i < N - 1; i++) {
            int temp = mods[i] += K;
            min = mods[i + 1];
            if(max < temp) {
                max = temp;
            }   
            if(diff > max - min) {
                diff = max - min;
            }
        }
        cout << diff << endl;
        return 0;
    }