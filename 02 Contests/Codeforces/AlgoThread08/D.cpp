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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int timer, n, m, w;
const int LG = 23, maxN = 3e5 + 5;
int tin[maxN], tout[maxN];
int up[maxN][LG + 1], mins[maxN][LG + 1], depth[maxN];
vector<pii> adj[maxN];

void dfs(int v = 1, int p = 1, int weight = INF, int d = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    mins[v][0] = weight;
    for (int i = 1; i <= LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mins[v][i] = min(mins[v][i-1], mins[up[v][i-1]][i-1]);
    }
    for (auto u : adj[v]) {
        if (u.fs != p) {
            dfs(u.fs, v, u.sc, d + 1);
        }
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = LG; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int getDist(int n1, int n2) {
	return depth[n1] + depth[n2] - 2 * depth[LCA(n1, n2)];
}

int getMin(int node, int dist) {
	int ans = INF;
	for (int i = 0; i <= LG; i++) {
		if (dist & (1LL << i)) {
			ans = min(ans, mins[node][i]);
			node = up[node][i];
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}
	int a, b;
	int q; cin >> q;
	dfs();
	while (q--) {
		cin >> a >> b;
		int lca = LCA(a, b);
		int ans = getMin(a, getDist(a, lca));
		ans = min(ans, getMin(b, getDist(b, lca)));
		cout << ans << endl;
	}
	return 0;
}