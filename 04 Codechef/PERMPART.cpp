#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int fastpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        vector<int> freq(2 * n + 1);
        int sure = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x > 2 * n) {
                sure++;
            } else {
                freq[x]++;
            }
        }

        vector<int> dp(2 * n + 1);
        for (int value = 1; value <= 2 * n; value++) {
            vector<int> dp2((2 * n) / value + 1);
            int suffix_min = dp.back();
            for (int i = (int) dp.size() - 1; i >= 0; i--) {
                suffix_min = min(dp[i], suffix_min);
                if (i < (int) dp2.size()) {
                    dp2[i] = abs(freq[value] - i) + suffix_min;
                }
            }
            dp = dp2;
        }

        cout << *min_element(dp.begin(), dp.end()) + sure << endl;
    }
    return 0;
}