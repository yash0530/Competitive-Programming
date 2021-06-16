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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int n;
vector<int> adj[105];
int arr[105];

void genTree(int parent, int low, int high) {
	if (low <= high) {
		int mx = max_element(arr + low, arr + high + 1) - arr;
		if (parent != -1) {
			adj[arr[parent]].pb(arr[mx]);
			adj[arr[mx]].pb(arr[parent]);
		}
		genTree(mx, low, mx - 1);
		genTree(mx, mx + 1, high);
	}
}

int depth[105];
void dfs(int node, int parent, int d) {
	depth[node] = d;
	for (auto x : adj[node]) {
		if (x != parent) {
			dfs(x, node, d + 1);
		}
	}
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		genTree(-1, 1, n);
		dfs(n, n, 0);
		for (int i = 1; i <= n; i++) {
			cout << depth[arr[i]] << " ";
		} cout << endl;
	}
	return 0;
}