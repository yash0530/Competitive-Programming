#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)
 
class Graph {
    private:
        vector<vector<int>> adj;
        int vertices;
        vector<bool> marked;
        bool hasCycle;
        
        void __depthFirstSearchCycle(int source, int parentSource) {
            marked[source] = true;
            for (auto v : adj[source]) {
                if (!marked[v]) {
                    __depthFirstSearchCycle(v, source);
                } else if (v != parentSource) {
                    hasCycle = true;
                }
            }
        }

        void __depthFirstSearchCycle() {
            marked.assign(vertices, false);
            for (int u = 1; u < vertices; u++) {
                if (!marked[u]) {
                    __depthFirstSearchCycle(u, -1);
                }
            }
        }

        void __depthFirstSearch(int source, vector<int> &dfs) {
            dfs.push_back(source);
            marked[source] = true;
            for (auto v : adj[source]) {
                if (!marked[v]) {
                    __depthFirstSearch(v, dfs);
                }
            }
        }
        
    public:
        Graph(int n) {
            vertices = n + 1;
            adj = vector<vector<int>>(vertices);
            hasCycle = false;
        }
        
        void _addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> _depthFirstSearch(int source) {
            vector<int> dfs;
            marked.assign(vertices, false);            
            __depthFirstSearch(source, dfs);
            return dfs;
        }

        vector<int> _breadthFirstSearch(int source) {
            vector<int> bfs;
            marked.assign(vertices, false);
            queue<int> q;
            q.push(source);
            marked[source] = true;
            while (!q.empty()) {
                int s = q.front(); q.pop();
                bfs.push_back(s);
                for (auto v : adj[s]) {
                    if (!marked[v]) {
                        marked[v] = true;
                        q.push(v);
                    }
                }
            } return bfs;
        }

        bool _hasCycle() {
            __depthFirstSearchCycle();
            return hasCycle;
        }
};