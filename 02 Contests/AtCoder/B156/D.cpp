#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
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

int factmod(int n, int k) {
    int res = 1;
    int t = k;
    while (k--) {
        res = (res * (n - k)) % HELL;
    }
    int den = 1;
    while (t--) {
        den = (den * (t + 1)) % HELL;
    }
    den = fastpow(den, HELL - 2, HELL);
    res = (res * den) % HELL;
    return res;
}

int now() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int n, a, b;
    cin >> n >> a >> b;
    int res = (fastpow(2, n, HELL) - 1) % HELL;
    res = (res - factmod(n, a) - factmod(n, b) + 2 * HELL) % HELL;
    cout << res << endl;
    return 0;
}