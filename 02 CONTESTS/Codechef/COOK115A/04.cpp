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

vector<bool> P(1e6 + 5, true);

int32_t main() { fastio;
    vector<int> primes;
    for (int i = 2; i * i < 1e6 + 5; i++) {
        if (P[i]) {
            for (int j = i * i; j < 1e6 + 5; j += i) {
                P[j] = false;
            }
        }
    }
    for (int i = 2; i < 1e6 + 5; i++) {
        if (P[i]) {
            primes.push_back(i);
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int res = 1;
        for (auto p : primes) {
            if (p > n) {
                break;
            }
            if (k % p) {
                int x = p;
                int count = 0;
                while (x <= n) {
                    count += (n / x);
                    x *= p;
                }
                res = (res * fastpow(p, count, HELL)) % HELL;
            }
        }
        cout << res << endl;
    }
    return 0;
}