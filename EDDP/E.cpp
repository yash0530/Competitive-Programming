#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, w;
    cin >> n >> w;
    vector<ll> weights(n), vals(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> vals[i];
    }
    int max_val = 0;
    for (auto x : vals) {
        max_val += x;
    }

    // dp[i] => minimum weight required to get i value
    vector<ll> dp(max_val + 1, 1e18 + 1);
    dp[0] = 0;
    for (int item = 0; item < n; item++) {
        for (int j = max_val; j >= vals[item]; j--) {
            dp[j] = min(dp[j], dp[j - vals[item]] + weights[item]);
        }
    }

    for (int i = max_val; i >= 0; i--) {
        if (dp[i] <= w) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}