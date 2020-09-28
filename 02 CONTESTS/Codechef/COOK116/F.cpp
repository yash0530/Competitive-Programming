#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, x;
const int maxW = 5e5 + 5;
int c[maxW], d[maxW];

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        cin >> n;
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        for (int i = 0; i < n; i++) {
            cin >> x; c[x]++;
        }
        int total_pairs = ((n + 1) * (2 * n + 1)) % HELL;
        total_pairs = (total_pairs * fastpow(6, HELL - 2, HELL)) % HELL;

        for (int i = 1; i < maxW; i++) {
            for (int j = i; j < maxW; j += i) {
                d[i] += c[j];
            }
            d[i] = d[i] * d[i];
        }
        int gcd = 0;
        for (int i = maxW - 1; i >= 1; i--) {
            for (int j = 2 * i; j < maxW; j += i) {
                d[i] -= d[j];
            }
            gcd = (gcd + ((i * d[i]) % HELL)) % HELL;
        }
        gcd = (gcd * fastpow(n * n, HELL - 2, HELL)) % HELL;
        int res = (total_pairs * gcd) % HELL;
        cout << res << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}