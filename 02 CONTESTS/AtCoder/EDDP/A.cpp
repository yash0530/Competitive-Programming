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
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(abs(arr[i - 2] - arr[i]) + dp[i - 2], abs(arr[i - 1] - arr[i]) + dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
 
    return 0;
}
