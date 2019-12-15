#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl
using namespace std;
using namespace boost::multiprecision; 

ll dp[1001][1001];

ll getRes(vector<ll> &arr, ll low, ll high) {
    if (low > high) {
        return 0;
    }

    if (dp[low][high] != -1) {
        return dp[low][high];
    }

    ll res = 0;

    res = max(arr[low] + min(getRes(arr, low + 2, high), getRes(arr, low + 1, high - 1)),
              arr[high] + min(getRes(arr, low + 1, high - 1), getRes(arr, low, high - 2)));

    dp[low][high] = res;
    return dp[low][high];
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, sum = 0; cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    memset(dp, -1, sizeof dp);
    cout << 2 * getRes(arr, 0, n - 1) - sum << endl;

    return 0;
}