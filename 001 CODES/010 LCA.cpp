#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int n, l, timer;
        vector<vector<int>> adj, up;
        vector<int> tin, tout;

        void __depthFirstSearch(int v, int p) {
            tin[v] = ++timer;
            up[v][0] = p;
            for (int i = 1; i <= l; ++i) {
                up[v][i] = up[up[v][i-1]][i-1];
            }
            for (int u : adj[v]) {
                if (u != p) {
                    __depthFirstSearch(u, v);
                }
            }
            tout[v] = ++timer;
        }

    public:
        Graph(int vertex) {
            n = vertex + 1;
            l = ceil(log2(n));
            adj.assign(n, vector<int>());
        }

        void _addEdge(int a, int b) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool _isAncestor(int u, int v) {
            return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
        }

        void _preProcess(int root) {
            tin.resize(n);
            tout.resize(n);
            timer = 0;
            up.assign(n, vector<int>(l + 1));
            __depthFirstSearch(root, root);
        }

        int _LCA(int u, int v) {
            if (_isAncestor(u, v)) {
                return u;
            }
            if (_isAncestor(v, u)) {
                return v;
            }
            for (int i = l; i >= 0; --i) {
                if (!_isAncestor(up[u][i], v)) {
                    u = up[u][i];
                }
            }
            return up[u][0];
        }
};