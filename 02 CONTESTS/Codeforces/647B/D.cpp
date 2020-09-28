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

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 5];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int> arr(n + 5);
	vector<pii> nodes;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		nodes.pb({ arr[i], i });
	}
	sort(nodes.begin(), nodes.end());
	vector<bool> marked(n + 5);
	bool poss = true;
	for (auto no : nodes) {
		set<int> found;
		for (auto x : adj[no.sc]) {
			if (marked[x]) {
				found.insert(arr[x]);
			}
		}
		int ct = 1;
		for (auto f : found) {
			if (ct != f) {
				break;
			}
			ct++;
		}
		if (ct != no.fs) {
			poss = false;
		}
		marked[no.sc] = true;
	}
	if (poss) {
		for (auto no : nodes) {
			cout << no.sc << " ";
		}			
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
