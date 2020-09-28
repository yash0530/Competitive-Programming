#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < 29; i++) {
        vector<int> x(n);
        int k = (1 << (i + 1));
        for (int i = 0; i < n; i++) {
            x[i] = arr[i] % k;
        }
        sort(x.begin(), x.end());
        int count = 0;
        int k1 = (1 << i), k2 = (1 << (i + 1)), k3 = (1 << (i + 2));
        for (int i = 0; i < n; i++) {
            int a = k1 - x[i];
            int b = k2 - 1 - x[i];
            int c = k2 + k1 - x[i];
            int d = k3 - 2 - x[i];
            if (a > 0) {
                count += (upper_bound(x.begin() + i + 1, x.end(), b) - lower_bound(x.begin() + i + 1, x.end(), a));
            } else {
                count += (upper_bound(x.begin() + i + 1, x.end(), b) - (x.begin() + i + 1));
            }
            if (c > 0) {
                count += (upper_bound(x.begin() + i + 1, x.end(), d) - lower_bound(x.begin() + i + 1, x.end(), c));
            } else {
                count += (upper_bound(x.begin() + i + 1, x.end(), d) - (x.begin() + i + 1));
            }
        }
        if (count & 1) {
            res |= (1 << i);
        }
    }
    cout << res << endl;
    cerr << "TIME => " << now() - start << endl;
    return 0;
}