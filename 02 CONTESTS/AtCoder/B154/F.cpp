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

vector<int> fact(4e6 + 5);

int nck(int n, int k) {
    return ((fastpow(fact[n - k], HELL - 2, HELL)) * 
            ((fact[n] * fastpow(fact[k], HELL - 2, HELL)) % HELL)) % HELL;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = (i * fact[i - 1]) % HELL;
    }

    // using hockey stick identity
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int res = 0;
    for (int i = r1; i <= r2; i++) {
        res = (res + nck(i + c2 + 1, i + 1)) % HELL;
        res = (res + HELL - nck(i + c1, i + 1)) % HELL;
    }
    cout << res << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}