// CSES Building Roads
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

int n, m;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
bool vis[maxN];

void dfs(int node) {
	vis[node] = true;
	for (auto x : adj[node]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			res.pb(i);
		}
	}
	cout << size(res) - 1 << endl;
	for (int i = 1; i < size(res); i++) {
		cout << res[0] << " " << res[i] << endl;
	}
	return 0;
}