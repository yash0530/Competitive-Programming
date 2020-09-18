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

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = size(g) - 1;
    vector<int> centroid;
    vector<int> sz(n + 1);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(1, -1);
    return centroid;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, x, b; cin >> n;
		vector<vector<int>> adj(n + 1);
		for (int i = 1; i < n; i++) {
			cin >> x >> b;
			adj[x].pb(b);
			adj[b].pb(x);
		}
		vector<int> ctds = Centroid(adj);
        if (size(ctds) == 1) {
            for (int i = 1; i <= n; i++) {
                if (size(adj[i])) {
                    cout << i << " " << adj[i][0] << endl;
                    cout << i << " " << adj[i][0] << endl;
                    break;
                }
            }
        } else {
            int node = -1;
            for (auto x : adj[ctds[0]]) {
                if (x != ctds[1]) {
                    node = x;
                    break;
                }
            }
            cout << ctds[0] << " " << node << endl;
            cout << ctds[1] << " " << node << endl;
        }
	}
	return 0;
}