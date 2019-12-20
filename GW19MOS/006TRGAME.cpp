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

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

vector<vector<int>> adj;
vector<int> ans;
vector<bool> marked;
int n;

int dfs(int curr) {
    marked[curr] = true;
    vector<int> subtrees;
    int sum = 0;
    for (auto u :adj[curr]) {
        if (!marked[u]) {
            int x = dfs(u);
            sum += x;
            subtrees.push_back(x);
        }
    }
    if (n - sum - 1) subtrees.push_back(n - sum - 1);
    int M = *max_element(subtrees.begin(), subtrees.end());
    if (M <= (n / 2)) {
        ans[curr] = 1;
    }
    return sum + 1;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        adj.assign(n + 1, {});
        ans.assign(n + 1, 0);
        marked.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (n & 1) {
            for (int i = 0; i < n; i++) {
                cout << 0;
            } cout << endl;
        } else {
            dfs(1);
            for (int i = 1; i <= n; i++) {
                cout << ans[i];
            } cout << endl;
        }

    }
    return 0;
}