#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 998244353
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

vector<int> fact(2e5 + 5);

int nck(int n, int k) {
    return ((fastpow(fact[n - k], HELL - 2, HELL)) * 
            ((fact[n] * fastpow(fact[k], HELL - 2, HELL)) % HELL)) % HELL;
}

int32_t main() { fastio;
    time_t start = now();

    fact[0] = 1;
    for (int i = 1; i < (int) fact.size(); i++) {
        fact[i] = (i * fact[i - 1]) % HELL;
    }
    int n, m;
    cin >> n >> m;
    int res = ((nck(m, n - 1) * fastpow(2, n - 2, HELL)) % HELL * (n - 2)) % HELL;
    cout << (res * fastpow(2, HELL - 2, HELL)) % HELL << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}