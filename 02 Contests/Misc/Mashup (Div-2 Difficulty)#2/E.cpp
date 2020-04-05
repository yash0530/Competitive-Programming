#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int n, m, q, timer;
const int maxN = 1e5 + 5, maxM = 1e5 + 5, maxA = 10, LG = 21;
vector<int> adj[maxN];
int up[maxN][LG], tin[maxN], tout[maxN];
vector<int> arr[maxN];
vector<int> people[maxN][LG];

void merge(vector<int> &a, vector<int> &b, vector<int> &res, int mx) {
    int i = 0, j = 0;
    int alen = a.size(), blen = b.size();
    while (mx--) {
    	if (i < alen and j < blen) {
    		if (a[i] == b[j]) {
    			res.push_back(a[i]);
    			i++; j++;
    		} else if (a[i] < b[j]) {
    			res.push_back(a[i]);
    			i++;
    		} else {
    			res.push_back(b[j]);
    			j++;
    		}
    	} else if (i < alen) {
    		res.push_back(a[i]);
			i++;
    	} else if (j < blen) {
    		res.push_back(b[j]);
			j++;
    	} else {
    		return;
    	}
    }
}

void dfs(int v = 1, int p = 1) {
    tin[v] = ++timer;
    up[v][0] = p;

    // adding people
    merge(arr[p], arr[v], people[v][0], maxA);

    for (int i = 1; i < LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];

        // adding people
        merge(people[v][i-1], people[up[v][i-1]][i-1], people[v][i], maxA);
    }
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }
    for (int i = LG - 1; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

vector<int> tillLCA(int node, int lca, int a) {
	vector<int> res;
	merge(arr[lca], arr[node], res, a);
	if (node != lca) {
		for (int i = LG - 1; i >= 0; --i) {
	        if (!isAncestor(up[node][i], lca)) {
				vector<int> temp;
	            merge(people[node][i], res, temp, a);
	            res = temp;
	            node = up[node][i];
	        }
	    }
	}
	vector<int> temp;
	merge(arr[node], res, temp, a);
	res = temp;
	return res;
}

int32_t main() { fastio;
	int u, v, a;
	cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) {
		cin >> u;
		arr[u].push_back(i);
	}
	dfs();
	while (q--) {
		cin >> u >> v >> a;
		int lca = LCA(u, v);
		vector<int> res, left = tillLCA(u, lca, a), right = tillLCA(v, lca, a);
		merge(left, right, res, a);
		cout << res.size() << " ";
		for (auto r : res) {
			cout << r << " ";
		} cout << endl;
	}
    return 0;
}
