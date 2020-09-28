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

int n, u, v;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int dp[maxN], ans[maxN], sizes[maxN];

int dfs1(int curr = 1, int parent = 1) {
	int sz = 1;
	for (auto x : adj[curr]) {
		if (x != parent) {
			sz += dfs1(x, curr);
			dp[curr] += dp[x];
		}
	}
	dp[curr] += sz;
	sizes[curr] = sz;
	return sz;
}

void dfs2(int curr = 1, int parent = 1, int val = 0) {
	ans[curr] = dp[curr] + val - sizes[curr] + n;
	for (auto x : adj[curr]) {
		if (x != parent) {
			dfs2(x, curr, ans[curr] - dp[x] - sizes[x]);
		}
	}
}

int32_t main() { fastio;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(); dfs2();
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, ans[i]);
	}
	cout << mx << endl;
	return 0;
}
