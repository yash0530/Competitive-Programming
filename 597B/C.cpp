#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
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
    string s; cin >> s;
    int n = s.length();
    vector<int> prefix(n, 1);
    bool poss = true;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'u' and s[i] == s[i - 1]) {
            prefix[i] = prefix[i - 1] + 1;
            prefix[i - 1] = 1;
        }
        if (s[i] == 'n' and s[i] == s[i - 1]) {
            prefix[i] = prefix[i - 1] + 1;
            prefix[i - 1] = 1;
        }
        if (s[i] == 'm' or s[i] == 'w') {
            poss = false;
            break;
        }
    }
    if (s[0] == 'm' or s[0] == 'w') poss = false;
    if (!poss) {
        cout << 0 << endl;
    } else {    
        vector<int> dp(n + 1);
        if (n >= 2) dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % HELL;
        }
        int res = 1;
        for (auto p : prefix) {
            res = (res * dp[p]) % HELL;
        }
        cout << res << endl;
    }
    return 0;
}