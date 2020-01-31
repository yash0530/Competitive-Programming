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
    int t; cin >> t;
    while (t--) {
        int n, q, a, b;
        cin >> n >> q;
        vector<int> edges[n + 1];
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        map<pair<int, int>, set<int>> dist_mat;
        for (int i = 1; i <= n; i++) {
            queue<pair<int, int>> Q;
            vector<bool> marked(n + 1);
            Q.push({ i, 0 });
            marked[i] = true;
            while (!Q.empty()) {
                int curr = Q.front().first;
                int dist = Q.front().second;
                dist_mat[{ i, dist }].insert(curr);
                Q.pop();
                for (auto x : edges[curr]) {
                    if (!marked[x]) {
                        marked[x] = true;
                        Q.push({ x, dist + 1 });
                    }
                }
            }
        }
        while (q--) {
            int a, da, b, db;
            cin >> a >> da >> b >> db;
            auto x = dist_mat[{ a, da }];
            auto y = dist_mat[{ b, db }];
            vector<int> res;
            set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(res));
            if (res.size() == 0) {
                cout << -1 << endl;
            } else {
                cout << res[0] << endl;
            }
        }
    }
    return 0;
}