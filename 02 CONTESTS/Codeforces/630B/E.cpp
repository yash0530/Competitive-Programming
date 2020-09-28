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
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int32_t main() { fastio;
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int t = n * m;

    int total = fastpow(r - l + 1, n * m, HELL);
    if (t & 1) {
    	cout << total << endl;
    } else {
    	int a = (r - l + 1) / 2;
    	int b = (r - l + 1) - a;
    	int sub = ((fastpow(a + b, t, HELL) - fastpow(a - b, t, HELL)) + HELL) % HELL;
    	total = (total - ((sub * inv(2)) % HELL) + HELL) % HELL;
    	cout << total << endl;
    }

    return 0;
}
