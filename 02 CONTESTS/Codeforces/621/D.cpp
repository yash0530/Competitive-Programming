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

bool custom(const pii &a, const pii &b) {
	return (a.fs - a.sc) < (b.fs - b.sc);
}

int32_t main() { fastio;
	int n, m, k, u, v;
	cin >> n >> m >> k;
	vector<int> specials(k);
	for (int i = 0; i < k; i++) {
		cin >> specials[i];
	}
	vector<int> adj[n + 5];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<pii> dist(n + 5);
	queue<pii> Q;
	Q.push({ 1, 0 });
	vector<bool> marked(n + 5);
	marked[1] = true;
	while (!Q.empty()) {
		pii now = Q.front(); Q.pop();
		dist[now.fs].fs = now.sc;
		for (auto x : adj[now.fs]) {
			if (!marked[x]) {
				marked[x] = true;
				Q.push({ x, now.sc + 1 });
			}
		}
	}
	Q.push({ n, 0 });
	marked = vector<bool>(n + 5, 0);
	marked[n] = true;
	while (!Q.empty()) {
		pii now = Q.front(); Q.pop();
		dist[now.fs].sc = now.sc;
		for (auto x : adj[now.fs]) {
			if (!marked[x]) {
				marked[x] = true;
				Q.push({ x, now.sc + 1 });
			}
		}
	}
	int res = dist[n].fs;
	vector<pii> sps;
	for (auto s : specials) {
		sps.pb(dist[s]);
	}
	sort(sps.begin(), sps.end(), custom);
	vector<int> suff(k + 1);
	for (int i = k - 1; i >= 0; i--) {
		suff[i] = max(suff[i + 1], sps[i].sc);
	}
	int here = 0;
	for (int i = 0; i < k - 1; i++) {
		here = max(here, sps[i].fs + suff[i + 1] + 1);
	}
	cout << min(here, res) << endl;
	return 0;
}
