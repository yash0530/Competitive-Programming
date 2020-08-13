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

int n, tot;
bool poss;
const int maxN = 1e5 + 5;
int p[maxN], h[maxN];
vector<int> adj[maxN];

int people[maxN];

int dfs1(int source = 1, int parent = 1) {
	people[source] += p[source];
	for (auto a : adj[source]) {
		if (a != parent) {
			people[source] += dfs1(a, source);
		}
	}
	return people[source];
}

void dfs2(int source = 1, int parent = 1) {
	int t = 0;
	for (auto a : adj[source]) {
		if (a != parent) {
			t += h[a];
			dfs2(a, source);
		}
	}
	if (t > (h[source] + p[source])) poss = false;
}

void dfs3(int val, int source = 1, int parent = 1) {
	if ((h[source] < -people[source]) or (h[source] > people[source])) poss = false;
	if ((abs(h[source]) & 1) != ((people[source]) & 1)) poss = false;
	for (auto a : adj[source]) {
		if (a != parent) {
			dfs3(h[source], a, source);
		}
	}
}

int32_t main() {

	int t; cin >> t;
	while (t--) {

		cin >> n >> tot;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) cin >> h[i];
		int u, v;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		poss = true;
		for (int i = 1; i <= n; i++) people[i] = 0;

		dfs1();
		dfs2();
		dfs3(tot);

		if (poss) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}

	return 0;
}