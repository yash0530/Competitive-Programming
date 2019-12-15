#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> torn(m);
        for (int i = 0; i < m; i++) {
            cin >> torn[i];
        }
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            res[i] = n / i;
        }
        for (auto x : torn) {
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    if (i * i == x) {
                        res[i]--;
                    } else {
                        res[i]--;
                        res[x / i]--;
                    }
                }
            }
        }
        int ans = 0;
        while (q--) {
            int a; cin >> a;
            ans += res[a];
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}