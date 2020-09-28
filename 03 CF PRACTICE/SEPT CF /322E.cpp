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

int nn, n;
const int maxN = 1e5 + 5;
int sub[maxN], par[maxN];
set<int> adj[maxN];
char res[maxN];

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

int32_t main() { fastio;
	cin >> n;
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	decompose(1, -1);
	vector<vector<int>> centroid_tree(n + 1);
	int root;
	for (int i = 1; i <= n; i++) {
		if (par[i] == i) {
			root = i;
		} else {
			centroid_tree[par[i]].pb(i);
			centroid_tree[i].pb(par[i]);
		}
	}
	queue<pair<int, char>> Q;
	vector<int> vis(n + 1);
	Q.push({ root, 'A' });
	vis[root] = true;
	while (!Q.empty()) {
		auto tp = Q.front(); Q.pop();
		res[tp.fs] = tp.sc;
		for (auto x : centroid_tree[tp.fs]) {
			if (!vis[x]) {
				vis[x] = true;
				Q.push({ x, tp.sc + 1 });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	} cout << endl;
	return 0;
}