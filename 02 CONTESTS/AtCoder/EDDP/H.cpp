#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl
#define MOD 1000000007

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string mat[n];
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int dp[n][m];
    memset(dp, 0, sizeof dp);
    dp[0][0] = mat[0][0] == '.';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                dp[i][j] = (dp[i][j] + (i > 0 ? dp[i - 1][j] : 0)) % MOD;
                dp[i][j] = (dp[i][j] + (j > 0 ? dp[i][j - 1] : 0)) % MOD;
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;

    return 0;
}