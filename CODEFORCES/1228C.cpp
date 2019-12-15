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

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> getPrimeFactors(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (isPrime(i)) {
                res.push_back(i);
            }
            if (i * i != x) {
                if (isPrime(x / i)) {
                    res.push_back(x / i);
                }
            }
        }
    }
    return res;
}

int32_t main() {
    fastio;
    int x, n;
    cin >> x >> n;
    vector<int> factors = getPrimeFactors(x);
    int res = 1;
    for (auto f : factors) {
        int num = n, count = 0;
        while (num >= f) {
            num /= f;
            count += num;
        }
        res = (res * binpow(f, count, MOD)) % MOD;
    }
    cout << res << endl;
    return 0;
}