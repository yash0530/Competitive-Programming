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
        int vertices;
        vector<int> *adj;
        vector<int> color;
        vector<bool> marked;
        bool isBipartite;
 
    public:
        Graph(int V) {
            vertices = V + 1;
            adj = new vector<int>[vertices];
        }
 
        void _addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        void _printGraph() {
            for (int i = 1; i < vertices; i++) {
                for (auto v : adj[i])
                    cout << i << " <-> " << v << endl;
                cout << endl;
            }
        }
 
        void _breadthFirstSearch(int source, int c) {
            queue <int> ver;
            ver.push(source);

            marked[source] = true;
            color[source] = c;
 
            while (!ver.empty()) {
                int curr = ver.front(); ver.pop();
                int child_color = !color[curr];

                for (auto v : adj[curr]) {
                    if (!marked[v]) {
                        ver.push(v);
                        marked[v] = true;
                        color[v] = child_color;
                    } else if (color[v] != child_color) {
                        isBipartite = false;
                        return;
                    }
                }
            }
        }

        bool _isBipartite() {
            marked.assign(vertices, false);
            color.assign(vertices, -1);
            isBipartite = true;
            for (int i = 1; i < vertices; i++) {
                if (!marked[i])
                    _breadthFirstSearch(i, 0);
                if (!isBipartite) break;
            }
            return isBipartite;
        }
};