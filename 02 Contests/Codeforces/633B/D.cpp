#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb emplace_back
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
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
vector<int> paths;

void dfs(int root, int parent, int level) {
	if (size(adj[root]) == 1 and root != parent) {
		paths.pb(level);
		return;
	}
	for (auto x : adj[root]) {
		if (x != parent) {
			dfs(x, root, level + 1);
		}
	}
}

int32_t main() { fastio;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int> leafs;
	for (int i = 1; i <= n; i++) {
		if (size(adj[i]) == 1) leafs.pb(i);
	}
	int m = 0, root = leafs[0];
	vector<bool> marked(n + 1);
	for (auto l : leafs) {
		if (!marked[adj[l][0]]) {
			marked[adj[l][0]] = true;
			m++;
		}
	}
	dfs(root, root, 0);
	int o = 0;
	for (auto p : paths) {
		o += (p & 1);
	}
	if (o) {
		cout << 3 << " " << n - 1 - size(leafs) + m << endl;
	} else {
		cout << 1 << " " << n - 1 - size(leafs) + m << endl;
	}
	return 0;
}