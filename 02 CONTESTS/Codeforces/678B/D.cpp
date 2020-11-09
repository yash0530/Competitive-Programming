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
vector<int> adj[maxN];
vector<int> vals(maxN);
vector<int> sizes(maxN);

pii dfs(int root, int par) {
	if (root != 1 and size(adj[root]) == 1) {
		sizes[root] = 1;
		return make_pair(vals[root], 1LL);
	}
	int sz = 0, val = vals[root];
	for (auto x : adj[root]) {
		if (x != par) {
			auto xx = dfs(x, root);
			sz += xx.sc;
			val += xx.fs;
		}
	}
	sizes[root] = sz;
	vals[root] = val;
	return { val, sz };
};

int32_t main() { fastio;
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}
	if (n == 1) {
		cout << vals[1] << endl;
		exit(0);
	}
	dfs(1, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, (vals[i] + sizes[i] - 1) / sizes[i]);
	}
	cout << ans << endl;
	return 0;
}