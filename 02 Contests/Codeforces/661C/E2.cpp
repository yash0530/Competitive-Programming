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

struct comp {
	bool operator()(const pii &a, const pii &b) {
		return (((a.fs + 1) / 2) * a.sc) < (((b.fs + 1) / 2) * b.sc);
	}
};

int n, s;
const int maxN = 1e5 + 5;
vector<vector<int>> adj[maxN];
priority_queue<pii, vector<pii>, comp> ones, tows;
int sum = 0;

int dfs(int source = 1, int parent = 1) {
	int count = 0;
	int sz = 0;
	for (auto a : adj[source]) {
		if (a[0] != parent) {
			int curr = dfs(a[0], source);
			if (a[2] == 1)
				ones.push({ a[1],  curr });
			else
				tows.push({ a[1], curr });
			sum += a[1] * curr;
			sz += curr;
			count++;
		}
	}
	if (count) return sz;
	return 1;
}

int32_t main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		int u, v, w, t;
		for (int i = 1; i < n; i++) {
			cin >> u >> v >> w >> t;
			adj[u].pb({ v, w, t });
			adj[v].pb({ u, w, t });
		}
		dfs();
		int count = 0;
		while (sum > s) {
			pii one1 = ones.top(); ones.pop();
			pii one2 = ones.top(); ones.pop();
			pii two = tows.top(); tows.pop();

			if (sum - (((one1.fs + 1) / 2) * one1.sc)) 

			sum -= ((tp.fs + 1) / 2) * tp.sc;
			pq.push({ tp.fs / 2, tp.sc });
			

			count++;
		}
		cout << count << endl;

		while (!ones.empty()) ones.pop();
		while (!tows.empty()) tows.pop();
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		sum = 0;
	}
	return 0;
}