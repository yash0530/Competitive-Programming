#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
#define trav(e, x) for (const auto &(e) : (x))
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define lc(i) 2*i
#define rc(i) 2*i+1
//#define int long long
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vii = vector<ii>;
using vivi = vector<vi>;

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e9 + 5;
vi g[N];
int col[N], upto[N], from[N];
int ans;

struct SegmentTree {
    int n;
    vector<int> t;

    void init(int x) {
        n = x;
        t.assign(4 * n, 0);
    }

    int merge(int x, int y) { return max(x, y); }

    int upd(int x, int y) { return max(x, y); }

    void modify(int i, int l, int r, int pos, int val) {
        if (l > pos || r < pos) return;
        if (l >= pos && r <= pos) {
            t[i] = upd(t[i], val);
            return;
        }
        int mid = (l + r) / 2;
        modify(lc(i), l, mid, pos, val);
        modify(rc(i), mid + 1, r, pos, val);
        t[i] = merge(t[lc(i)], t[rc(i)]);
    }

    void set(int i, int l, int r, int pos, int val) {
        if (l > pos || r < pos) return;
        if (l >= pos && r <= pos) {
            t[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        set(lc(i), l, mid, pos, val);
        set(rc(i), mid + 1, r, pos, val);
        t[i] = merge(t[lc(i)], t[rc(i)]);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return t[i];
        int mid = (l + r) / 2;
        int resL = query(lc(i), l, mid, ql, qr);
        int resR = query(rc(i), mid + 1, r, ql, qr);
        return merge(resL, resR);
    }

    void modify(int pos, int val) { modify(1, 0, n - 1, pos, val); }

    void set(int pos, int val) { set(1, 0, n - 1, pos, val); }

    int query(int l, int r) { return query(1, 0, n - 1, l, r); }

    int query(int pos) { return query(1, 0, n - 1, pos, pos); }
};

SegmentTree seg;

void precomp(int u = 0, int p = -1) {
    if (p != -1 && col[u] >= col[p]) upto[u] += upto[p];
    trav(v, g[u]) {
        if (v == p) continue;
        precomp(v, u);
        if (col[u] <= col[v]) from[u] = max(from[u], from[v] + 1);
    }
}

void dfs(int u, int p) {
    int mx = seg.query(0, col[u]);
    if (mx == 0) mx = -1;
    ans = max(ans, mx + from[u]);
    int prev = seg.query(col[u]); // Store previous value for rollback
    seg.modify(col[u], upto[u]); // Set the value for further nodes
    trav(v, g[u]) if (v != p) dfs(v, u);
    seg.set(col[u], prev); // Rollback the change you made at this node
}

void solve() {
    int n;
    cin >> n;
    vi compress;
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        compress.pb(col[i]);
    }
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    for (int i = 0; i < n; i++) col[i] = lower_bound(all(compress), col[i]) - compress.begin();
    for (int i = 0; i < n; i++) g[i].clear();
    ans = 0;
    seg.init(n);
    for (int i = 0; i < n; i++) upto[i] = from[i] = 1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    precomp();
    seg.modify(col[0], 1);
    trav(v, g[0]) dfs(v, 0);
    cout << ans << "\n";
}

signed main() {
    FAST_IO;
//    setIO("input.txt", "output.txt");

    int t;
    cin >> t;
    while (t--) solve();
}