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

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int sum = accumulate(arr.begin(), arr.end(), 0);
        for (int i = n; i < 10 * n; i++) {
            arr.push_back(sum / n);
            sum -= arr[i - n];
            sum += arr[i];
        }

        int N = arr.size();

        int q; cin >> q;
        int x;
        while (q--) {
            cin >> x;
            if (x <= N) {
                cout << arr[x - 1] << endl;
            } else {
                cout << arr.back() << endl;
            }
        }
    }
    return 0;
}