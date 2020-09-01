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

int n, q, val;
const int maxN = 3e5 + 5;
double tree[4 * maxN], arr[maxN];
vector<int> adj[maxN];
pii dfsM[maxN];

// dfs ordering
void dfs(int u = 1, int p = 1) {
	dfsM[u].fs = ++val;
	for (auto x : adj[u]) {
		if (x != p) {
			dfs(x, u);
		}
	}
	dfsM[u].sc = val;
}

// sum over range
double sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v*2, tl, tm) + sum(max(l, tm+1), r, v*2+1, tm+1, tr);
}

// update a loc
void update(int pos, double new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

int32_t main() { fastio;
	cin >> n;
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	val = -1; dfs();
	cin >> q;
	int t, x, y;
	while (q--) {
		cin >> t >> x >> y;
		if (t == 1) {
			update(dfsM[x].fs, log10(y));
		} else {
			double a = sum(dfsM[x].fs, dfsM[x].sc);
			double b = sum(dfsM[y].fs, dfsM[y].sc);

			if ((a - b) >= 9) {
				cout << (int)1e9 << endl;
			} else {
				pout << pow(10, a - b) << endl;
			}
		}
	}
	return 0;
}