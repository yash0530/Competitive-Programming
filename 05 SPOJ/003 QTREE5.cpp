#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 1e16
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

const int maxN = 1e5 + 5;
set<int> adj[maxN];

// --------------------------- BIN LIFT        ----------------------------- //
int timer;
const int LG = 22;
int tin[maxN], tout[maxN];
int up[maxN][LG + 1];
int depth[maxN];
void dfs(int v = 1, int p = 1, int d = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i <= LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
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

int dist(int a, int b) {
	int lca = LCA(a, b);
	return depth[a] + depth[b] - depth[lca] * 2;
}

// --------------------------- CENTROID DECOMP ----------------------------- //
int nn;
int sub[maxN], par[maxN];

void dfs1(int u,int p) {
	sub[u] = 1; nn++;
	for(auto v : adj[u]) {
		if(v != p) {
			dfs1(v, u);
			sub[u] += sub[v];
		}
	}
}

int dfs2(int u,int p) {
	for(auto v : adj[u]) {
		if((v != p) and (sub[v] > nn / 2)) {
			return dfs2(v, u);
		}
	}
	return u;
}

void decompose(int root,int p) {
	nn = 0;
	dfs1(root, root);
	int centroid = dfs2(root, root);
	if(p == -1) p = centroid;
	par[centroid] = p;
	for(auto v : adj[centroid]) {
		adj[v].erase(centroid);
		decompose(v, centroid);
	}
	adj[centroid].clear();
}

// --------------------------- QUERIES         ----------------------------- //
multiset<int> ans[maxN];
bool state[maxN];

void update(int node) {
	if (state[node]) {
		int curr = node;
		while (true) {
			ans[curr].erase(ans[curr].find(dist(curr, node)));
			if (par[curr] == curr) break;
			curr = par[curr];
		}
	} else {
		int curr = node;
		while (true) {
			ans[curr].insert(dist(curr, node));
			if (par[curr] == curr) break;
			curr = par[curr];
		}
	}
	state[node] = !state[node];
}

int query(int node) {
	int val = *ans[node].begin();
	int curr = node;
	while (true) {
		val = min(val, dist(curr, node) + *ans[curr].begin());
		if (par[curr] == curr) break;
		curr = par[curr];
	}
	return val;
}

int32_t main() { fastio;
	int n, m;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	// bin lift
	dfs();

	// centroid decomp
	decompose(1, -1);

	// solution
	for (int i = 1; i <= n; i++) ans[i].insert(INF);

	cin >> m;
	while (m--) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			update(x);
		} else {
			int val = query(x);
			if (val == INF) {
				cout << -1 << endl;
			} else {
				cout << val << endl;
			}
		}
	}

	return 0;
}
