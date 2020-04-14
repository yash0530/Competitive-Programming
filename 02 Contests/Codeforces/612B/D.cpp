#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

const int maxN = 2005;
int n, root;
int c[maxN], sz[maxN], ans[maxN];
vector<int> adj[maxN], order[maxN];

void add(vector<int> &a, vector<int> &b) {
	for (auto x : b) a.push_back(x);
}

void dfs(int source = root, int parent = root) {
	sz[source] = 1;
	for (auto u : adj[source]) {
		if (u != parent) {
			dfs(u, source);
			sz[source] += sz[u];
			add(order[source], order[u]);
		}
	}
	if (c[source] >= sz[source]) {
		cout << "NO" << endl;
		exit(0);
	}
	order[source].insert(order[source].begin() + c[source], source);
}

int32_t main() { fastio;
	
	int x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x) {
			adj[i].push_back(x);
			adj[x].push_back(i);
		} else {
			root = i;
		}
		c[i] = y;
	}

	dfs();
	for (int i = 1; i <= n; i++) {
		ans[order[root][i - 1]] = i;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	} cout << endl;

    return 0;
}
