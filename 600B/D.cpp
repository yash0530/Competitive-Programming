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

class Graph {
    private:
        vector<vector<int>> adj;
        int vertices, count, curr_max;
        vector<bool> marked;

        void __depthFirstSearch(int source) {
            marked[source] = true;
            curr_max = max(curr_max, source);
            for (auto v : adj[source]) {
                if (!marked[v]) {
                    __depthFirstSearch(v);
                }
            }
        }

    public:
        Graph(int n) {
            vertices = n + 1;
            adj = vector<vector<int>>(vertices);
        }
        
        void _addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int _depthFirstSearch() {
            marked = vector<bool>(vertices);
            count = curr_max = 0;
            for (int i = 1; i < vertices; i++) {
                if (!marked[i]) {
                    if (curr_max > i) {
                        count++;
                    }
                    __depthFirstSearch(i);
                }
            }
            return count;
        }
};

int32_t main() { fastio;
    int n, m, a, b;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G._addEdge(a, b);
    }
    cout << G._depthFirstSearch() << endl;
    return 0;
}