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
    int val, weight;
    vector<ll> dp(w + 1);

    for (ll i = 0; i < n; i++) {
        cin >> weight >> val;
        for (int j = w; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + val);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}