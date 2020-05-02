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

int n, m, u, v;
const int maxN = 5e3 + 5;
vector<int> adj[maxN];
int res[maxN];
map<pii, int> edges;
int marked[maxN];

void dfs(int curr) {
	marked[curr] = 1;
	for (auto x : adj[curr]) {
		if (marked[x] == 0) { dfs(x);
			res[edges[{ curr, x }]] = 1;
		} else if (marked[x] == 1) {
			res[edges[{ curr, x }]] = 2;
		} else {
			res[edges[{ curr, x }]] = 1;
		}
	}
	marked[curr] = 2;
}

int32_t main() { fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		edges[{ u, v }] = i;
		adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!marked[i]) dfs(i);
	}
	cout << *max_element(res, res + m) << endl;
	for (int i = 0; i < m; i++) {
		cout << res[i] << " ";
	} cout << endl;
	return 0;
}
