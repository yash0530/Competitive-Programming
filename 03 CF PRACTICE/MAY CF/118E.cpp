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

int n, m;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];

vector<bool> visited;
vector<int> tin, low;
set<int> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.insert({ v, to });
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

vector<int> T;
void print(int node = 1, int parent = 1, int t = 0) {
	T[node] = t;
	visited[node] = true;
	for (auto x : adj[node]) {
		if (!visited[x]) {
			cout << node << " " << x << endl;
			print(x, node, ++t);
		} else if (x != parent and T[x] < T[node]) {
			cout << node << " " << x << endl;
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	find_bridges();
	if (size(bridges)) {
		cout << 0 << endl;
	} else {
		visited.assign(n + 1, false);
		T.assign(n + 1, 0);
		print();
	}
	return 0;
}
