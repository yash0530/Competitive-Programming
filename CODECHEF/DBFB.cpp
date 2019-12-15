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

int32_t main() {
    fastio;
    int t; cin >> t;

    vector<int> fib(100002);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 100002; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    while (t--) {
        int m, n; cin >> m >> n;
        vector<int> a(m), b(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int x, y;
        if (n == 1) {
            x = 1, y = 0;
        } else if (n == 2) {
            x = 0, y = 1;
        } else {
            x = fib[n - 2], y = fib[n - 1];
        }

        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum = (sum + ((((a[i] % MOD) * (x % MOD)) % MOD) * (m)) % MOD) % MOD;
            sum = (sum + ((((b[i] % MOD) * (y % MOD)) % MOD) * (m)) % MOD) % MOD;
        }
        cout << sum << endl;
    }
    return 0;
}