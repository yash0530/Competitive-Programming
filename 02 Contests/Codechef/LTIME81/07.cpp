#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define int long long
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int maxN = 1e5 + 5, maxLG = 20;

// dfs pre ordering
int id;
vector<vector<int>> adj;
int dfs_in[maxN], vals[maxN], dfs_out[maxN], inv_dfs[maxN];

// kth lca
int LG;
int up[maxN][maxLG];

void dfs(int v = 1, int p = 1, int level = 0) {
    dfs_in[v] = id;
    vals[id] = level;
    inv_dfs[id] = v;
    id++;

    up[v][0] = p;
    for (int i = 1; i <= LG; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (auto x : adj[v]) {
        if (x != p) {
            dfs(x, v, level + 1);
        }
    }
    dfs_out[v] = id - 1;
}

int kthLCA(int node, int k) {
    for (int i = 0; i <= LG; i++) {
        if ((1 << i) & k) {
            node = up[node][i];
        }
    }
    return node;
}

// segment tree
int n; pair<int, int> tree[4 * maxN];
stack<pair<int, pair<int, int>>> changes;

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = { a[tl], tl };
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return;
    if (l == tl and tr == r) {
        changes.push({ v, tree[v] });
        tree[v] = { -1, INF };
        return;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
        changes.push({ v, tree[v] });
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {

        cin >> n; LG = log2(ceil(n));
        adj = vector<vector<int>> (n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        id = 0;

        dfs();
        build(vals, 1, 0, n - 1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            auto x = tree[1];
            int alpha = 0, count = 0;
            while (x.first >= 0) {
                int node = kthLCA(inv_dfs[x.second], i);
                update(1, 0, n - 1, dfs_in[node], dfs_out[node]);
                x = tree[1];
                ans++;
            }
            while (!changes.empty()) {
                tree[changes.top().first] = changes.top().second;
                changes.pop(); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}