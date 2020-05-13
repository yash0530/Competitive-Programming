#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n, res;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
int vals[maxN];

void dfs(int u, int p, map<int, int> M) {
	map<int, int> m;
	for (auto y : M) {
		m[__gcd(y.fs, vals[u])] += y.sc;
	}
	m[vals[u]]++;
	for (auto a : m) {
		res = (res + mul(a.fs, a.sc)) % HELL;
	}
	for (auto x : adj[u]) {
		if (x != p) {
			dfs(x, u, m);
		}
	}
}

int32_t main() { fastio;
	cin >> n;
	int u, v;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	map<int, int> M;
	dfs(1, 1, M);
	cout << res << endl;
	return 0;
}
