#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = max(0, i - k); j < i; j++) {
            dp[i] = min(dp[i], abs(arr[j] - arr[i]) + dp[j]);
        }
    }
    cout << dp[n - 1] << endl;

    return 0;
}