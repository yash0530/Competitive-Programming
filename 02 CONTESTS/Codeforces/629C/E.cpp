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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}
 
int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}
 
int n, k, timer, m;
const int maxK = 2e5 + 5;
const int maxN = 2e5 + 5;
const int l = 17;
int arr[maxK], tin[maxN], tout[maxN], depth[maxN];
vector<int> adj[maxN];
int up[maxN][l + 1];


void dfs(int v = 1, int p = 1, int level = 1) {
    depth[v] = level;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, level + 1);
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
    for (int i = l; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

bool possible() {
    for (int i = 0; i < k - 1; i++) {
        int lca = LCA(arr[k - 1], arr[i]);
        if (lca != arr[i] and up[arr[i]][0] != lca) {
            return false;
        }
    }
    return true;
}

int32_t main() { fastio;
    time_t start = now();
 
    int n;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    while (m--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + k, [](int const &a1, int const &a2) {
            return depth[a1] < depth[a2];
        });
        if (possible()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
 
    cerr << "TIME => " << now() - start << endl;
    return 0;
}