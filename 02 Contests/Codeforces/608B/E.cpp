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

int count(int x, int n) {
    int res = 0, base;
    if (x & 1) {
        base = 1;
    } else {
        base = 2;
    }
    while (x <= n) {
        int low = x, high = min(x + base - 1, n);
        res += (high - low + 1);
        base *= 2;
        x *= 2;
    }
    return res;
}

int32_t main() { fastio;
    int n, k;
    cin >> n >> k;
    int lo = 1, hi = n / 2, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (count(mid * 2, n) >= k) {
            res = mid * 2;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    lo = 0, hi = (n - 1) / 2;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (count(mid * 2 + 1, n) >= k) {
            res = max(res, 2 * mid + 1);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}