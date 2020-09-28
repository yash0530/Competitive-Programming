#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int n, m;
    cin >> n >> m;
    int dp[n][m][2];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < m; i++) {
        dp[0][i][0] = i % 2;
        dp[0][i][1] = 0; 
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0 and i > 1) {
                dp[i][j][0] += dp[i - 2][j - 1][1];
                dp[i][j][1] += dp[i - 2][j - 1][0];
            }
            if (j < m - 1 and i > 1) {
                dp[i][j][0] += dp[i - 2][j + 1][1];
                dp[i][j][1] += dp[i - 2][j + 1][0];
            }
            if (j > 1) {
                dp[i][j][0] += dp[i - 1][j - 2][1];
                dp[i][j][1] += dp[i - 1][j - 2][0];
            }
            if (j < m - 2) {
                dp[i][j][0] += dp[i - 1][j + 2][1];
                dp[i][j][1] += dp[i - 1][j + 2][0];
            }
            dp[i][j][0] %= HELL;
            dp[i][j][1] %= HELL;
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum = (sum + dp[n - 1][i][1]) % HELL;
    }
    cout << sum << endl;
    cerr << "TIME => " << now() - start << endl;
    return 0;
}