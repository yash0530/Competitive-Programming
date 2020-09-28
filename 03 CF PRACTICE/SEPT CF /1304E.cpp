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

int timer;
const int LG = 22, maxN = 1e5 + 5;
int tin[maxN], tout[maxN];
int up[maxN][LG + 1];
vector<int> adj[maxN];
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

int32_t main() { fastio;
	int n; cin >> n;
	int u, v;
	for (int i = 0; i < (n - 1); i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs();
	int q; cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int p1 = dist(a, b);
		int p2 = dist(a, x) + dist(b, y) + 1;
		int p3 = dist(a, y) + dist(b, x) + 1;
		if (p1 <= k and !((p1 & 1) ^ (k & 1))) {
			cout << "YES" << endl;
		} else if (p2 <= k and !((p2 & 1) ^ (k & 1))) {
			cout << "YES" << endl;
		} else if (p3 <= k and !((p3 & 1) ^ (k & 1))) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}