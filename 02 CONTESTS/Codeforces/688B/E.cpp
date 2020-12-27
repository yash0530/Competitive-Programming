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

int n, ans;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];

int dfs(int u, int p) {
	vector<int> depths;
	for (auto x : adj[u]) {
		if (x != p) {
			depths.pb(dfs(x, u));
		}
	}
	if (size(depths)) {
		sort(_all(depths));
		for (int i = 1; i < size(depths); i++) {
			ans = max(ans, depths[i] + 1);
		}
		return depths[0] + 1;
	}
	return 1;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int u, v;
		ans = 0;
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		vector<int> vals;
		for (auto x : adj[1]) {
			vals.pb(dfs(x, 1));
		}
		sort(_all(vals));
		for (int i = 0; i < size(vals) - 1; i++) {
			ans = max(ans, vals[i] + 1);
		}
		ans = max(ans, vals.back());
		cout << ans << endl;
	}
	return 0;
}