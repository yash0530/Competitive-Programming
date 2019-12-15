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

class WeightedUF {
    private:
        vector<int> arr;
        vector<int> size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            arr = vector<int>(v + 1);
            size = vector<int>(v + 1);
            for (int i = 0; i <= v; i++) {
                size[i] = 1;
                arr[i] = i;
            }
        }

        void _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            if (rootA == rootB) return;
            
            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
        }

        bool _find(int a, int b) {
            return __root(a) == __root(b);
        }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int32_t main() { fastio;
    int n; cin >> n;
    vector<pair<int, int>> locs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> locs[i].first >> locs[i].second;
    }
    vector<int> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        edges.push_back({ 0, i, c[i] });
        for (int j = i + 1; j <= n; j++) {
            edges.push_back({ i, j, (k[i] + k[j]) * dist(locs[i], locs[j]) });
        }
    }

    vector<Edge> mst;
    sort(edges.begin(), edges.end());
    int cost = 0;
    WeightedUF uf(n);
    vector<int> power;
    vector<pair<int, int>> roads;
    for (auto e : edges) {
        if (!uf._find(e.u, e.v)) {
            cost += e.weight;
            mst.push_back(e);
            uf._union(e.u, e.v);
            
            if (e.u == 0) {
                power.push_back(e.v);
            } else {
                roads.push_back({ e.u, e.v });
            }
        }
    }
    cout << cost << endl;
    cout << power.size() << endl;
    sort(power.begin(), power.end());
    for (auto p : power) {
        cout << p << " ";
    } cout << endl;
    sort(roads.begin(), roads.end());
    cout << roads.size() << endl;
    for (auto r : roads) {
        cout << r.first << " " << r.second << endl;
    } cout << endl;
    return 0;
}