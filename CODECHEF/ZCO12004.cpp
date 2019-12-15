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
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            dp[1] = arr[1];
        } else {
            dp[i] = arr[i] + min(dp[i - 1], dp[i - 2]);
        }
    }
    vector<int> dp2(n);
    dp2[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (i == n - 2) {
            dp2[i] = arr[n - 2];
        } else {
            dp2[i] = arr[i] + min(dp2[i + 1], dp2[i + 2]);
        }
    }
    if (n == 1) cout << arr[0] << endl;
    else cout << min(dp[n - 1], dp2[0]) << endl;
    return 0;
}