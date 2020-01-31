#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
 
int n, m, x, y;
vector<vector<int>> adj;
vector<bool> by_x;
vector<bool> by_y;
 
void dfs(int source, vector<bool> &visited) {
    for (auto a : adj[source]) {
        if (!visited[a] and a != x and a != y) {
            visited[a] = true;
            dfs(a, visited);
        }
    }
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        int a, b;
        adj.assign(n + 1, {});
        by_x.assign(n + 1, 0);
        by_y.assign(n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        by_x[x] = true;
        dfs(x, by_x);
        by_y[y] = true;
        dfs(y, by_y);
        for (int i = 1; i <= n; i++) {
            if (by_x[i] and by_y[i]) {
                by_x[i] = by_y[i] = 0;
            }
        }
        cout << (int) accumulate(by_x.begin(), by_x.end(), -1) * (int) accumulate(by_y.begin(), by_y.end(), -1) << endl;
    }
    return 0;
}