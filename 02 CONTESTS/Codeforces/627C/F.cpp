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
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n;
vector<int> ans, arr, dp;
vector<vector<int>> adj;

void dfs1(int source = 1, int parent = -1) {
    dp[source] = arr[source];
    for (auto v : adj[source]) {
        if (v != parent) {
            dfs1(v, source);
            dp[source] += max(dp[v], 0LL);
        }
    }
}

void dfs2(int source = 1, int parent = -1, int p_value = 0) {
    ans[source] = dp[source] + p_value;
    for (auto v : adj[source]) {
        if (v != parent) {
            dfs2(v, source, max(ans[source] - max(dp[v], 0LL), 0LL));
        }
    }
}

int32_t main() { fastio;
    time_t start = now();

    int n; cin >> n;
    arr.resize(n + 5); ans.resize(n + 5);
    dp.resize(n + 5); adj.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = !arr[i] ? -1 : 1;
    }
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(); dfs2();
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    } cout << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}