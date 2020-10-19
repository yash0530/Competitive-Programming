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

int32_t main() { fastio;
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<int> okay(n + 1);
	vector<vector<int>> qs(k + 1);
	for (int i = 1; i <= n; i++) {
		cin >> okay[i];
		qs[okay[i]].pb(i);
	}
	int u, v;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<vector<int>> dists(n + 1);
	for (int i = 1; i <= k; i++) {
		vector<bool> vis(n + 1);
		queue<pii> Q;
		for (auto x : qs[i]) {
			vis[x] = true;
			Q.push({ x, 0 });
		}
		while (!Q.empty()) {
			auto tp = Q.front(); Q.pop();
			dists[tp.fs].pb(tp.sc);
			for (auto x : adj[tp.fs]) {
				if (!vis[x]) {
					vis[x] = true;
					Q.push({ x, tp.sc + 1 });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(dists[i].begin(), dists[i].end());
		int sum = 0;
		for (int j = 0; j < s; j++) {
			sum += dists[i][j];
		}
		cout << sum << " ";
	}
	return 0;
}