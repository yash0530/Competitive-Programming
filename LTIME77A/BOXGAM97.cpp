#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define int long long
#define uint unsigned long long
#define MOD (int) (1e9 + 7)
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    } return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (k & 1) {
            if (p == 0) {
                cout << *max_element(arr.begin(), arr.end()) << endl;
            } else {
                cout << *min_element(arr.begin(), arr.end()) << endl;
            }
        } else {
            if (p == 0) {
                int res = max(arr[1], arr[n - 2]);
                for (int i = 1; i < n - 1; i++) {
                    res = max(res, min(arr[i - 1], arr[i + 1]));
                }
                cout << res << endl;
            } else {
                int res = min(arr[1], arr[n - 2]);
                for (int i = 1; i < n - 1; i++) {
                    res = min(res, max(arr[i - 1], arr[i + 1]));
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}