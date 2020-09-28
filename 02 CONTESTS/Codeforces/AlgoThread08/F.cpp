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

int n, q, val, timer;
const int maxN = 3e5 + 5, LG = 20;
int tree[4 * maxN], arr[maxN], tin[maxN], tout[maxN], up[maxN][LG + 1];
vector<int> adj[maxN];
pii dfsM[maxN];

// dfs ordering
void dfs(int v = 1, int p = 1) {
	tin[v] = ++timer;
	dfsM[v].fs = ++val;
	up[v][0] = p;
	for (int i = 1; i <= LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
	for (auto x : adj[v]) {
		if (x != p) {
			dfs(x, v);
		}
	}
	dfsM[v].sc = ++val;
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


// sum over range
double sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v*2, tl, tm) + sum(max(l, tm+1), r, v*2+1, tm+1, tr);
}

// update a loc
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> q;
		int u, v;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		n *= 2;
		val = -1; dfs();
		int a, b, x;
		while (q--) {
			cin >> a >> b >> x;
			if (!x) {
				int lca = LCA(a, b);
				deb(lca);
				int ans = sum(dfsM[1].fs, dfsM[a].fs) + sum(dfsM[1].fs, dfsM[b].fs);
				ans -= 2 * sum(dfsM[1].fs, dfsM[lca].fs);
				cout << abs(ans) << endl;
			} else {
				update(dfsM[a].fs, x);
				update(dfsM[a].sc, -x);
				update(dfsM[b].fs, -x);
				update(dfsM[b].sc, x);
			}
		}

		for (int i = 1; i <= n; i++) adj[i].clear();
		memset(tree, 0, sizeof tree);
		memset(arr, 0, sizeof arr);
		memset(dfsM, 0, sizeof dfsM);
		timer = 0;
	}
	return 0;
}