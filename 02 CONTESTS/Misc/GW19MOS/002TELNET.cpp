#include <bits/stdc++.h>
using namespace std;

#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int p;

class Graph {
    private:
        vector<vector<Edge>> adj;
        vector<int> dp;
        int vertices;

        int __dfs(int node, int curr, int &cost) {

            if (dp[node] != -1) {
                cost = min(curr + dp[node], cost);
                return dp[node];
            }
            
            int s = adj[node].size();
            if (s == 0) {
                cost = min(cost, curr);
                dp[node] = 0;                
                return 0;
            }
            int val = 1e9;
            for (auto u : adj[node]) {
                curr += u.weight;
                val = min(val, __dfs(u.v, curr, cost) + u.weight);
                curr -= u.weight;
            }

            dp[node] = val;
            return val;
        }
        
    public:
        Graph(int n) {
            vertices = n + 1;
            adj = vector<vector<Edge>>(vertices);
            dp.resize(vertices, -1);
        }
        
        void _addEdge(int u, int v, int cost) {
            adj[u].push_back({ u, v, cost });
        }

        int _getMinCost() {
            int cost = 1e9, curr = 0;
            __dfs(0, curr, cost);
            return cost;
        }
};

int32_t main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        getMat(mat, n, n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        int N = (n) * (n);
        Graph graph(N);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 1) {
                    graph._addEdge(0, i * n + j + 1, 0);
                }

                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (x != i or y != j) {
                            if (mat[i][j] == mat[x][y] - 1) {
                                graph._addEdge(i * n + j + 1, x * n + y + 1, abs(i - x) + abs(j - y));
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", graph._getMinCost());
    }
    return 0;
}