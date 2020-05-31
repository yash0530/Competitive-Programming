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

int32_t main() { fastio;
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n + 1];
	vector<int> radj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		radj[v].pb(u);
	}
	int x; cin >> x;
	vector<int> path(x);
	for (int i = 0; i < x; i++) {
		cin >> path[i];
	}
	vector<int> dist(n + 1);
	vector<bool> vis(n + 1);
	queue<pii> Q;
	vis[path.back()] = true;
	Q.push({ path.back(), 0 });
	while (!Q.empty()) {
		pii tp = Q.front(); Q.pop();
		dist[tp.fs] = tp.sc;
		for (auto y : radj[tp.fs]) {
			if (!vis[y]) {
				vis[y] = true;
				Q.push({ y, tp.sc + 1 });
			}
		}
	}
	int mn = 0, mx = 0;
	for (int i = 1; i < x - 1; i++) {
		int sm = INF;
		for (auto y : adj[path[i - 1]]) {
			sm = min(dist[y], sm);
		}
		if (dist[path[i]] != sm) {
			mn++; mx++;
		} else {
			int count = 0;
			for (auto y : adj[path[i - 1]]) {
				if (dist[y] == sm) count++;
			}
			if (count > 1) mx++;
		}
	}
	cout << mn << " " << mx << endl;
	return 0;
}
