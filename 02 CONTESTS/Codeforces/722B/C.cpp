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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

const int maxN = 2e5 + 5;
int32_t LR[maxN][2];
vector<int32_t> adj[maxN];
int dp[maxN][2];

void dfs(int curr, int par, int stat) {
	int &ans = dp[curr][stat];
	if (ans == -1) {
		int ans0 = 0, ans1 = 0;
		if (par != -1) {
			ans0 += abs(LR[par][stat] - LR[curr][0]);
			ans1 += abs(LR[par][stat] - LR[curr][1]);
		}
		for (auto x : adj[curr]) {
			if (x != par) {
				dfs(x, curr, 0);
				dfs(x, curr, 1);
				ans0 += dp[x][0];
				ans1 += dp[x][1];
			}
		}
		ans = max(ans0, ans1);
	}
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a, b;
		for (int i = 1; i <= n; i++) cin >> LR[i][0] >> LR[i][1];
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				dp[i][j] = -1;
			}
		}
		dfs(1, -1, 0);
		cout << dp[1][0] << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}