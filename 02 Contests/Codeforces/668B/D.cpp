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

int n, a, b, da, db;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
int diameter;

int dfs(int u = 1, int p = 1) {
	vector<int> lens;
	for (auto x : adj[u]) {
		if (x != p) {
			int curr = dfs(x, u);
			lens.pb(curr);
		}
	}
	sort(lens.begin(), lens.end(), greater<int>());
	int val = 0;
	if (size(lens)) {
		val = lens[0];
	}
	if (size(lens) > 1) {
		val += lens[1];
	}
	diameter = max(diameter, val);
	if (size(lens)) return lens[0] + 1;
	return 1;
}

int dist;
void dfs2(int root, int parent, int d) {
	if (root == b) {
		dist = d;
	}
	for (auto x : adj[root]) {
		if (x != parent) {
			dfs2(x, root, d + 1);
		}
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b >> da >> db;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		int x, y;
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		diameter = 0;
		dfs();
		dist = 0;
		dfs2(a, a, 0);

		db = min(db, diameter);

		if (dist <= da) {
			cout << "Alice" << endl;
		} else if ((da * 2 + 1) <= db) {
			cout << "Bob" << endl;
		} else {
			cout << "Alice" << endl;
		}
	}
	return 0;
}