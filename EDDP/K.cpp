#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl
using namespace std;
using namespace boost::multiprecision; 

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> dp(k + 1);
    for (int i = 0; i <= k; i++) {
        for (auto x : a) {
            if (i >= x and !dp[i - x]) {
                dp[i] = true;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;

    return 0;
}