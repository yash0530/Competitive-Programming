#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

const int maxN = 2e5 + 5;
int n, m, u, v;
vector<int> adj[maxN];
int dp[maxN];
vector<int> dist;

void dists() {
	vector<int> dd(n + 1, -1);
	dd[1] = 0;
	queue<int> pq;
	pq.push(1);
	while (!pq.empty()) {
		int u = pq.front();
		pq.pop();
		for (int v : adj[u]) {
			if (dd[v] == -1) {
				dd[v] = dd[u] + 1;
				pq.push(v);
			}
		}
	}
	dist = dd;
}

void dfs(int curr, vector<bool> &vis) {
	vis[curr] = true;
	dp[curr] = dist[curr];
	for (auto x : adj[curr]) {
		if (!vis[x] and dist[curr] < dist[x]) {
			dfs(x, vis);
		}

		if (dist[curr] < dist[x]) {
			dp[curr] = min(dp[curr], dp[x]);
		} else {
			dp[curr] = min(dp[curr], dist[x]);
		}
	}
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].pb(v);
		}
		vector<bool> vis(n + 1);
		dists(); dfs(1, vis);
		for (int i = 1; i <= n; i++) {
			cout << dp[i] << " ";
		} cout << endl;
	}
	return 0;
}