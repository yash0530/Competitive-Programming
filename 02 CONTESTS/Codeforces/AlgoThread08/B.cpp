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
const int maxN = 3e5 + 5;
vector<int> adj[maxN];

int32_t main() { fastio;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		exit(0);
	}
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int two = 1, dist = 0;
	queue<pii> Q;
	Q.push({ 1, 0 });
	vector<bool> vis(n + 1);
	vis[1] = true;
	while (!Q.empty()) {
		pii curr = Q.front(); Q.pop();
		if (dist < curr.sc) {
			dist = curr.sc;
			two = curr.fs;
		}
		for (auto x : adj[curr.fs]) {
			if (!vis[x]) {
				vis[x] = true;
				Q.push({ x, curr.sc + 1 });
			}
		}
	}

	int one = two;
	dist = 0;
	Q.push({ two, 0 });
	vis = vector<bool>(n + 1, false);
	vis[two] = true;
	while (!Q.empty()) {
		pii curr = Q.front(); Q.pop();
		if (dist < curr.sc) {
			dist = curr.sc;
			two = curr.fs;
		}
		for (auto x : adj[curr.fs]) {
			if (!vis[x]) {
				vis[x] = true;
				Q.push({ x, curr.sc + 1 });
			}
		}
	}

	set<int> S;
	S.insert(one);
	Q.push({ one, 0 });
	vis = vector<bool>(n + 1, false);
	vis[one] = true;
	while (!Q.empty()) {
		pii curr = Q.front(); Q.pop();
		if (dist == curr.sc) {
			S.insert(curr.fs);
		}
		for (auto x : adj[curr.fs]) {
			if (!vis[x]) {
				vis[x] = true;
				Q.push({ x, curr.sc + 1 });
			}
		}
	}

	Q.push({ two, 0 });
	vis = vector<bool>(n + 1, false);
	vis[two] = true;
	while (!Q.empty()) {
		pii curr = Q.front(); Q.pop();
		if (dist == curr.sc) {
			S.insert(curr.fs);
		}
		for (auto x : adj[curr.fs]) {
			if (!vis[x]) {
				vis[x] = true;
				Q.push({ x, curr.sc + 1 });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (S.find(i) != S.end()) {
			cout << dist + 1 << endl;
		} else {
			cout << dist << endl;
		}
	}

	return 0;
}