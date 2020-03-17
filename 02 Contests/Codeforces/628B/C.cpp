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

int32_t main() { fastio;
    time_t start = now();

    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
    } 
    vector<int> res(n - 1, -1);
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) {
            found = true;
            res[adj[i][0].second] = 0;
            res[adj[i][1].second] = 1;
            res[adj[i][2].second] = 2;
            break;
        }
    }
    if (found) {
        int val = 3;
        for (int i = 0; i < n - 1; i++) {
            if (res[i] == -1) {
                cout << val++ << endl;
            } else {
                cout << res[i] << endl;
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            cout << i << endl;
        }
    }
    cerr << "TIME => " << now() - start << endl;
    return 0;
}