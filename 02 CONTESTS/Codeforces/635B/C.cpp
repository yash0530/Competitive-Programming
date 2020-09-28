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

int n, k, res;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int inds[maxN], values[maxN];

int dfs(int root = 1, int parent = 1, int d = 0) {
	values[root] = d;
	int size = 1;
	for (auto x : adj[root]) {
		if (x != parent) {
			size += dfs(x, root, d + 1);
		}
	}
	values[root] -= size - 1;
	return size;
}

void dfs2(int root = 1, int parent = 1, int curr = 0) {
	if (inds[root]) {
		res += curr;
	}
	for (auto x : adj[root]) {
		if (x != parent) {
			dfs2(x, root, curr + !inds[root]);
		}
	}
}

int32_t main() { fastio;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}		
	dfs();
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ values[i], i });
	}
	while (k-- and !pq.empty()) {
		inds[pq.top().sc] = true;
		pq.pop();
	}
	dfs2();
	cout << res << endl;
	return 0;
}
