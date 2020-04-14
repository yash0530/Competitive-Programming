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
#define size(a) (int) a.size()

int32_t main() { fastio;
	int n, u, v;
	cin >> n;
	vector<int> degs(n + 1), fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % HELL;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		degs[u]++;
		degs[v]++;
	}
	int res = fact[degs[1]];
	for (int i = 2; i <= n; i++) {
		res = (res * fact[degs[i]]) % HELL;
	}
	res = (res * n) % HELL;
	cout << res << endl;
    return 0;
}
