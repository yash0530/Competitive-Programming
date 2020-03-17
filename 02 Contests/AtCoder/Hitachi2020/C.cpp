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

vector<pair<int, int>> P;
vector<vector<int>> edges;
vector<int> dfs(int source, int parent, vector<int> &my) {
    vector<int> l1;
    for (auto v : edges[source]) {
        if (v != parent) {
            l1.push_back(v);
        }
    }
    vector<int> l3;
    for (auto v : edges[source]) {
        if (v != parent) {
            vector<int> MY;
            vector<int> l2 = dfs(v, source, MY);
            for (auto l : l1) {
                if (l != v) {
                    for (auto x : l2) {
                        P.push_back({ l, x });
                    }
                }
            }
            for (auto x : l2) {
                l3.push_back(x);
            }
            for (auto m : MY) {
                P.push_back({ source, m });
            }
        }
    }
    my = l3;
    return l1;
}

int32_t main() { fastio;
    time_t start = now();
    int n; cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> tp;
    dfs(1, - 1, tp);

    cerr << "TIME => " << now() - start << endl;
    return 0;
}