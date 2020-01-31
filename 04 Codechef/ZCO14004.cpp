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

int binpow(int a, int b, int m) {
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
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    getMat(dp, n, 2, 0);
    dp[0][0] = dp[0][1] = arr[0];
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            dp[i][0] = arr[i];
        } else if (i == 2) {
            dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
        } else {
            dp[i][0] = max(max(dp[i - 2][0], dp[i - 2][1]), max(dp[i - 3][0], dp[i - 3][1])) + arr[i];
        }
        dp[i][1] = arr[i] + dp[i - 1][0];
    }
    int res = max(dp[n - 1][0], dp[n - 1][1]);
    if (n > 1) {
        res = max(res, max(dp[n - 2][0], dp[n - 2][1]));
    }
    cout << res << endl;
    return 0;
}