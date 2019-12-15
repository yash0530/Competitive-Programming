#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<double> dp(n + 1, 0);
    dp[0] = 1;

    // iterating over all coins
    double p_head;
    for (int i = 1; i <= n; i++) {
        cin >> p_head;
        // ith coin can affect at most i coins
        for (int j = i; j >= 0; j--) {
            dp[j] = (j == 0 ? 0 : dp[j - 1] * p_head) + dp[j] * (1 - p_head);
        }
    }

    double res = 0;
    for (int i = 0; i <= n; i++) {
        if (i > n - i) {
            res += dp[i];
        }
    }
    cout << setprecision(10) << res << endl;

    return 0;
}