#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> coins(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            coins[i].resize(x);
            for (int j = 0; j < x; j++) {
                cin >> coins[i][j];
            }
        }
        int sum = 0;
        for (auto c : coins) {
            for (int i = 0; i < c.size() / 2; i++) {
                sum += c[i];
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (coins[i].size() & 1) {
                res.push_back(coins[i][coins[i].size() / 2]);
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        for (int i = 0; i < res.size(); i += 2) {
            sum += res[i];
        }
        cout << sum << endl;
    }
    return 0;
}