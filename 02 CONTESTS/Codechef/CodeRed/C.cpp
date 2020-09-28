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

#define MAXN (int) 1e5

int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(t[2*v] > x and t[2*v+1] > x) {
                if (t[2*v] <= t[2*v+1]) {
                    v = 2*v;
                    rv = mid;
                } else {
                    v = 2*v+1;
                    lv = mid+1;
                }
            } else if (t[2*v] > x) { 
                v = 2*v;
                rv = mid;
            } else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }
    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}

int32_t main() { fastio;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int arr_for_segtree[n];
    map<int, int> BFS_index;
    map<int, int> INV_BFS_index;
    queue<int> Q;
    Q.push(1);
    vector<int> marked(n + 1);
    marked[1] = true;
    int i = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        BFS_index[x] = i;
        INV_BFS_index[i] = x;
        arr_for_segtree[i++] = arr[x - 1];
        for (auto y : adj[x]) {
            if (!marked[y]) {
                marked[y] = true;
                Q.push(y);
            }
        }
    }
    build(arr_for_segtree, 1, 0, n - 1);
    int q; cin >> q;
    while (q--) {
        int stat; cin >> stat;
        if (stat == 2) {
            int x; cin >> x;
            int y = get_first(1, 0, n - 1, 0, n - 1, x);
            if (y == -1) {
                cout << -1 << endl;
            } else {
                cout << INV_BFS_index[y] << endl;
            }
        } else {
            int x, y;
            cin >> x >> y;
            update(1, 0, n - 1, BFS_index[x], y);
        }
    }
    return 0;
}