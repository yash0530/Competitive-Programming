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
const int maxN = 5e5 + 5;
int tree[4 * maxN];

int maxQuery(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(maxQuery(l, min(r, tm), v*2, tl, tm),
    	maxQuery(max(l, tm+1), r, v*2+1, tm+1, tr));
}

void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

vector<int> vals;
vector<int> cocomp(vector<int> arr) {
    vector<int> compress;
    int nn = size(arr);
    for (int i = 0; i < nn; i++) {
        compress.pb(arr[i]);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for (int i = 0; i < nn; i++) arr[i] = lower_bound(compress.begin(), compress.end(), arr[i]) - compress.begin();
    return arr;
}

int ans;
vector<int> adj[maxN];
int L[maxN], R[maxN];

void dfs1(int node, int par) {
	L[node] = (vals[node] >= vals[par]) ? L[par] + 1 : 1;
	for (int child : adj[node]) {
		if (child != par) {
			dfs1(child, node);
			R[node] = max(R[node], (vals[node] <= vals[child]) ? R[child] + 1 : 1);
		}
	}
	R[node] = max(R[node], 1LL);
}

void dfs2(int node, int par) {
	int mx = maxQuery(0, vals[node]);
	if (mx == 0) mx--;
	ans = max(ans, R[node] + mx);
	int old_val = maxQuery(vals[node], vals[node]);
	update(vals[node], max(old_val, L[node]));
	for (int child : adj[node]) {
		if (child != par) {
			dfs2(child, node);
		}
	}
	update(vals[node], old_val);
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		vals = vector<int>(n + 1);
		vals[0] = INT_MAX;
		for (int i = 1; i <= n; i++) {
			cin >> vals[i];
		}
		vals = cocomp(vals);
		int aa, bb;
		for (int i = 0; i < (n - 1); i++) {
			cin >> aa >> bb;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}

		dfs1(1, 1);
		dfs2(1, 1);
		cout << ans << endl;

		// cleanup
		if (t) {
			for (int i = 1; i <= n; i++) {
				adj[i].clear();
				L[i] = R[i] = 0;
			}
			ans = 0;
		}
	}
	return 0;
}
