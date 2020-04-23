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

int n, m, a, b, c, u, v;
const int maxN = 2e5 + 5;
int distA[maxN], distB[maxN], distC[maxN];
vector<int> adj[maxN];

void bfs(int root, int *dist) {
	queue<pii> Q;
	Q.push({ root, 0 });
	bool marked[n + 1];
	memset(marked, 0, sizeof marked);
	marked[root] = true;
	while (!Q.empty()) {
		int curr = Q.front().fs; 
		dist[curr] = Q.front().sc;
		Q.pop();
		for (auto x : adj[curr]) {
			if (!marked[x]) {
				marked[x] = true;
				Q.push({ x, dist[curr] + 1 });
			}
		}
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b >> c;
		int values[m], pref[m + 1];
		for (int i = 0; i < m; i++) {
			cin >> values[i];
		}
		sort(values, values + m);
		pref[0] = 0;
		for (int i = 0; i < m; i++) {
			pref[i + 1] = pref[i] + values[i];
		}
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(a, distA);bfs(b, distB);bfs(c, distC);
		int res = INF;
		for (int i = 1; i <= n; i++) {
			if ((distA[i] + distB[i] + distC[i]) > m) continue;
			res = min(res, pref[distA[i] + distB[i] + distC[i]] + pref[distB[i]]);
		}
		cout << res << endl;
	}
	return 0;
}
