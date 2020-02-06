#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

vector<vector<double>> dp;

double getRes(vector<int> &arr, int low, int high) {
    if (low > high) return 0;
    if (low == high) return arr[low];
    if (dp[low][high] != -1) return dp[low][high];
    dp[low][high] = (getRes(arr, low + 2, high) + arr[low] +
            getRes(arr, low + 1, high - 1) + arr[low] +
            getRes(arr, low, high - 2) + arr[high] +
            getRes(arr, low + 1, high - 1) + arr[high]) / 4;
    return dp[low][high];
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        dp = vector<vector<double>>(n, vector<double>(n, -1));
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        pout << getRes(arr, 0, n - 1) << endl;
    }
    return 0;
}