#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define MOD (int) (1e9 + 7)
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int32_t main() { fastio;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vals(n + 1, { 0, 0 });
    for (int i = 1; i <= n; i++) {
        cin >> vals[i].first;
    }
    vector<set<int>> edges(n + 1, set<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    int source; cin >> source;
    queue<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (i != source and edges[i].size() == 1) {
            leaves.push(i);
        }
    }
    while (!leaves.empty()) {
        int leaf = leaves.front(); leaves.pop();
        for (auto x : edges[leaf]) {
            if (leaf != source) {
                vals[x].second = max(vals[x].second, vals[leaf].first + vals[leaf].second);
            } else {
                vals[x].second = max(vals[x].second, vals[x].second);
            }
            edges[x].erase(leaf);
            if (x != source and edges[x].size() == 1) {
                leaves.push(x);
            }
        }
    }

    int subtree = 0, total = 0;
    queue<int> Q;
    Q.push(source);
    vector<bool> marked(n + 1);
    marked[source] = true;
    while (!Q.empty()) {
        int curr = Q.front(); Q.pop();
        total += vals[curr].first;
        subtree = max(subtree, vals[curr].second);
        if (edges[curr].size() > 0) { 
            for (auto x : edges[curr]) {
                if (!marked[x]) {
                    marked[x] = true;
                    Q.push(x);
                }
            }
        }
    }
    cout << subtree + total << endl;
    return 0;
}