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

int n, m, k;
const int maxN = 1e5 + 5;
vector<int> adj[maxN], dfs_tree[maxN];
vector<pii> backs;
bool vis[maxN];
int depth[maxN];

void genTree(int source = 1, int parent = 1, int d = 0) {
	depth[source] = d;
	for (auto x : adj[source]) {
		if (x != parent) {
			if (vis[x]) {
				backs.pb({ source, x });
			} else {
				vis[x] = true;
				dfs_tree[x].pb(source);
				dfs_tree[source].pb(x);
				genTree(x, source, d + 1);
			}
		}
	}
}

vector<int> curr;
vector<int> res;

void dfsCycle(int u, int p, int t) {
	curr.pb(u);
	if (t == u) {
		res = curr;
		return;
	}
	for (auto x : dfs_tree[u]) {
		if (x != p) {
			dfsCycle(x, u, t);
		}
	}
	curr.pop_back();
}

void printCycle(pii edge) {
	dfsCycle(edge.fs, edge.fs, edge.sc);
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
}

void printSet(pii edge) {
	dfsCycle(edge.fs, edge.fs, edge.sc);
	for (int i = 0, j = 0; i < ((k + 1) / 2); i++, j += 2) {
		cout << res[j] << " ";
	} cout << endl;
}


vector<int> ids;
void getSet(int u = 1, int p = 1, bool prev = false) {
	if (!prev) {
		ids.pb(u);
	}
	for (auto x : dfs_tree[u]) {
		if (x != p) {
			getSet(x, u, !prev);
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m >> k;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vis[1] = true;
	genTree();
	int sz = INF;
	for (auto b : backs) {
		sz = min(sz, abs(depth[b.fs] - depth[b.sc]) + 1);
	}
	if (sz > k) {
		cout << 1 << endl;
		if (size(backs)) {
			printSet(backs[0]);
		} else {
			getSet();
			int reqd = ((k + 1) / 2);
			if (size(ids) >= reqd) {
				for (int i = 0; i < reqd; i++) {
					cout << ids[i] << " ";
				} cout << endl;
			} else {
				vector<bool> yes(n + 1);
				for (auto i : ids) {
					yes[i] = true;
				}
				for (int i = 1, j = 0; j < reqd; i++) {
					if (!yes[i]) {
						cout << i << " ";
						j++;
					}
				} cout << endl;
			}
		}
	} else {
		cout << 2 << endl;
		for (auto b : backs) {
			if (sz == (abs(depth[b.fs] - depth[b.sc]) + 1)) {
				cout << sz << endl;
				printCycle(b);
				break;
			}
		}
	}
	return 0;
}
