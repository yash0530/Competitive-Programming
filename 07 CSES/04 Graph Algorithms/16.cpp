// CSES Longest Flight Route
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
vector<int> visited, res;

void topoDFS(int v) {
    visited[v] = true;
    for (auto a : adj[v]) {
        if (!visited[a]) {
            topoDFS(a); 
        }
    }
    res.pb(v);
}

vector<int> topoSort() {
    visited = vector<int>(n + 5);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topoDFS(i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

bool vis[maxN];
void dfs(int x) {
	vis[x] = true;
	for (auto y : adj[x]) {
		if (!vis[y]) dfs(y);
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].pb(b);
	}
	dfs(1);
	if (!vis[n]) {
		cout << "IMPOSSIBLE\n"; exit(0);
	}
	auto ts = topoSort();
	vector<int> final(n + 1, 0);
	vector<int> parent(n + 1);
	final[1] = 1;
	parent[1] = 1;
	for (auto t : ts) {
		if (final[t]) {
			for (auto x : adj[t]) {
				if ((final[t] + 1) > final[x]) {
					final[x] = final[t] + 1;
					parent[x] = t;
				}
			}
		}
	}
	vector<int> ans;
	int loc = n;
	while (parent[loc] != loc) {
		ans.pb(loc);
		loc = parent[loc];
	}
	ans.pb(1);
	reverse(ans.begin(), ans.end());
	cout << final[n] << endl;
	for (auto y : ans) cout << y << " ";
	cout << endl;
	return 0;
}