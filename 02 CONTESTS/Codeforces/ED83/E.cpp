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
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << "\t"; cerr << "\n";}
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

    int n; cin >> n;
    vector<int> arr(n);
    // dp[i][j] => range [i,j] can be converted to value dp[i][j]
    //          => if not possible dp[i][j] = -1
    getMat(dp, n, n, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for (int i = n - 2; ~i; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (~dp[i][k] and dp[i][k] == dp[k + 1][j]) {
                    dp[i][j] = dp[i][k] + 1;
                }
            }
        }
    }
    // dp2[i] => min size poss for first i elements
    vector<int> dp2(n + 1);
    for (int i = 1; i <= n; i++) {
        dp2[i] = i;
        for (int j = 0; j < i; j++) {
            if (~dp[j][i - 1]) {
                dp2[i] = min(dp2[i], dp2[j] + 1);
            }
        }
    }
    cout << dp2.back() << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}