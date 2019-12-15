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
    int n, k;
    cin >> n >> k;
    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    getMat(dp, n, 2, 0);
    dp[1][0] = a[0];
    dp[1][1] = b[0] + k;
    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + k, dp[i - 1][1]) + b[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    } cout << endl;
    return 0;
}