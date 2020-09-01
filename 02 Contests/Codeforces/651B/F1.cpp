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

int n;
const int maxN = 1e3 + 5;
vector<int> adj[maxN];
vector<int> nodes;

void getAllNodesAtDist(int source, int parent, int current, int dist) {
	if (current == dist) {
		nodes.pb(source);
	}
	for (auto x : adj[source]) {
		if (x != parent) {
			getAllNodesAtDist(x, source, current + 1, dist);
		}
	}
}

pii getNodeDist() {
	cout << "? " << size(nodes) << " ";
	for (auto n : nodes) {
		cout << n << " ";
	} cout << endl;
	int x, d; cin >> x >> d;
	return { x, d };
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		nodes.clear();
		for (int i = 1; i <= n; i++) {
			nodes.pb(i);
		}
		pii node = getNodeDist();
		int poss = node.fs;

		int low = 1, high = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			nodes.clear();
			getAllNodesAtDist(node.fs, node.fs, 0, mid);
			if (size(nodes)) {
				pii curr = getNodeDist();
				if (curr.sc == node.sc) {
					low = mid + 1;
					poss = curr.fs;
				} else {
					high = mid - 1;
				}
			} else {
				high = mid - 1;
			}
		}

		nodes.clear();
		getAllNodesAtDist(poss, poss, 0, node.sc);
		int ans = getNodeDist().fs;
		cout << "! " << poss << " " << ans << endl;
		string s; cin >> s;

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}