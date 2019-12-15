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

int getRes(int i, vector<int> &a, vector<int> &b, int h, int n, int h1, int h2) {
    if (i == n) {
        return ((h1 >= h) and (h2 >= h));
    }
    return getRes(i + 1, a, b, h, n, h1 + a[i], h2 + b[i]) +
           getRes(i + 1, a, b, h, n, h1, h2 + b[i]) +
           getRes(i + 1, a, b, h, n, h1 + a[i], h2);
}

int32_t main() {
    fastio;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++) {
            cin >> b[j];
        }
        int res = getRes(0, a, b, h, n, 0, 0);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}