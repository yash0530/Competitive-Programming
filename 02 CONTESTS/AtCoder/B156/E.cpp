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

int now() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
    .time_since_epoch()).count();
}

vector<int> fact(5e5 + 5);

int nck(int n, int k) {
    return ((fastpow(fact[n - k], HELL - 2, HELL)) * 
            ((fact[n] * fastpow(fact[k], HELL - 2, HELL)) % HELL)) % HELL;
}

int32_t main() { fastio;
    time_t start = now();
    
    int n, k;
    cin >> n >> k;

    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = (i * fact[i - 1]) % HELL;
    }

    int res = nck(2 * n - 1, n - 1);
    for (int i = k + 1; i < n; i++) {
        res = (res - (nck(n, i) * nck(n - 1, n - i - 1)) % HELL + HELL) % HELL;
    }
    cout << res << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}