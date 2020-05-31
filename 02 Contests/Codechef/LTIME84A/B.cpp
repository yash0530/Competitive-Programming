#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

int timer, n;
const int LG = 22, maxN = 2e5 + 5;
int tin[maxN], tout[maxN], depth[maxN];
int up[maxN][LG + 1], arr[maxN], radj[maxN];
vector<int> adj[maxN];

void dfs(int v = 1, int p = 1, int d = 0) {
	radj[v] = p;
    tin[v] = ++timer;
    depth[v] = d;
    up[v][0] = p;
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

void addToPath(vector<int> &path, int node, int parent) {
	while (node != parent) {
		path[arr[node]]++;
		node = radj[node];
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs();
		while (q--) {
			int x, y;
			cin >> x >> y;
			int lca = LCA(x, y);

			int dist;
			if (lca == x) {
				dist = depth[y] - depth[lca] + 1;
			} else if (lca == y) {
				dist = depth[x] - depth[lca] + 1;
			} else {
				dist = depth[x] + depth[y] - 2 * depth[lca] + 1;
			}

			if (dist > 100) {
				cout << 0 << endl;
				continue;
			}

			vector<int> path(105);
			path[arr[lca]]++;
			addToPath(path, x, lca);
			addToPath(path, y, lca);
			int res = INT_MAX;
			for (auto p : path) {
				if (p > 1) {
					res = 0;
				}
			}
			if (res == 0) {
				cout << 0 << endl;
			} else {
				vector<int> vec_path;
				for (int i = 1; i <= 100; i++) {
					if (path[i]) vec_path.pb(i);
				}
				for (int i = 1; i < size(vec_path); i++) {
					res = min(res, abs(vec_path[i] - vec_path[i - 1]));
				}	
				cout << res << endl;
			}
		}
	}
	return 0;
}
