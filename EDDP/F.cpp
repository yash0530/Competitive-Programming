#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    int m = b.length(), n = a.length();
    int dp[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = (i > 0 and j > 0 ? dp[i - 1][j - 1] : 0) + 1;
            } else {
                dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
            }
        }
    }

    string res;
    int i = n - 1, j = m - 1;
    while (i >= 0 and j >= 0) {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i--; j--;
        } else if ((i > 0 ? dp[i - 1][j] : 0) > (j > 0 ? dp[i][j - 1] : 0)) {
            i--;
        } else {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}