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

// dp[x][0] => when there is no edge between x and parent
// dp[x][1] => when there is edge between x and parent

int n, k;
bool cust(pii &a, pii &b) {
	return (a.fs - a.sc) > (b.fs - b.sc);
}

void dfs(int node, int parent, vector<pii> adj[], vector<vector<int>> &dp) {
	vector<pii> nds;
	for (auto x : adj[node]) {
		if (x.fs != parent) {
			dfs(x.fs, node, adj, dp);
			if ((dp[x.fs][1] + x.sc) > dp[x.fs][0]) {
				nds.pb({ dp[x.fs][1] + x.sc, dp[x.fs][0] });
			} else {
				dp[node][0] += dp[x.fs][0];
				dp[node][1] += dp[x.fs][0];
			}
		}
	}
	sort(nds.begin(), nds.end(), cust);
	for (int i = 0; i < min(k - 1, size(nds)); i++) {
		dp[node][0] += nds[i].fs;
		dp[node][1] += nds[i].fs;
	}
	if (size(nds) >= k) {
		dp[node][0] += nds[k - 1].fs;
		dp[node][1] += nds[k - 1].sc;
	}
	for (int i = k; i < size(nds); i++) {
		dp[node][0] += nds[i].sc;
		dp[node][1] += nds[i].sc;
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int u, v, w;
		cin >> n >> k;
		vector<pii> adj[n + 1];
		getMat(dp, n + 1, 2, 0);
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> w;
			adj[u].pb({ v, w });
			adj[v].pb({ u, w });
		}
		dfs(1, 1, adj, dp);
		cout << dp[1][0] << endl;
	}
	return 0;
}
