#include <bits/stdc++.h>
using namespace std;

#define NIL -1
#define endl "\n"
#define INF 9e18
#define int long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class WeightedUF {
    private:
        int vertices;
        int *arr;
        int *size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            vertices = v;
            arr = new int[v + 1];
            size = new int[v + 1];
            for (int i = 1; i <= v; i++) {
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
            return arr[__root(a)] == arr[__root(b)];
        }
};

class Graph 
{ 
    private:
        int V;
        vector<bool> marked;
        int comp_count;

        void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[]) {
            static int time = 0; 

            visited[u] = true; 

            disc[u] = low[u] = ++time; 

            for (auto v : adj[u]) { 

                if (!visited[v]) { 
                    parent[v] = u; 
                    bridgeUtil(v, visited, disc, low, parent);
                    low[u] = min(low[u], low[v]); 

                    if (low[v] > disc[u]) {
                        bridges.insert({ u, v });
                        bridges.insert({ v, u });
                    }
                } 

                else if (v != parent[u]) {
                    low[u] = min(low[u], disc[v]); 
                }
	        }
        }

        void dfs(int u) {
            comps[u] = comp_count;
            for (auto x : adj[u]) {
                if (!marked[x] and (bridges.find({ u, x }) == bridges.end())) {
                    marked[x] = true;
                    dfs(x);
                }
            }
        }

    public: 
        vector<int> comps;
        set<pair<int, int>> bridges;
        vector<vector<int>> adj;

        Graph(int v) {
            V = v + 1; 
	        adj = vector<vector<int>>(V); 
            marked = vector<bool>(V);
            comps = vector<int>(V);
            comp_count = 0;
        }

        void addEdge(int v, int w) {
            adj[v].push_back(w); 
	        adj[w].push_back(v);
        }

        void markBridges() {
            bool *visited = new bool[V]; 
            int *disc = new int[V]; 
            int *low = new int[V]; 
            int *parent = new int[V]; 

            for (int i = 0; i < V; i++)  { 
                parent[i] = NIL; 
                visited[i] = false; 
            } 

            for (int i = 0; i < V; i++) {
                if (visited[i] == false) {
                    bridgeUtil(i, visited, disc, low, parent); 
                }
            }
        }

        void generateComps() {
            markBridges();
            marked[0] = true;
            for (int i = 1; i < V; i++) {
                if (!marked[i]) {
                    marked[i] = true;
                    comp_count++;
                    dfs(i);
                }
            }
        }
};

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Graph graph(n);
        vector<pair<int, int>> edges(m + 1);
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph.addEdge(a, b);
            edges[i] = { a, b };
        }
        graph.generateComps();

        auto comps = graph.comps;

        vector<int> size(n + 1);
        for (auto c : comps) {
            if (c) size[c]++;
        }
        int counts = 0, val;
        for (int i = 1; i <= n; i++) {
            if (size[i] > 1) {
                counts++;
                val = i;
            }
        }

        if (counts == 1) {
            vector<int> vertices;
            for (int i = 0; i <= n; i++) {
                if (comps[i] == val) {
                    vertices.push_back(i);
                }
            }
            int N = vertices.back();

            Graph g(N);
            WeightedUF uf(N);

            vector<pair<int, int>> E;
            for (auto e : edges) {
                if (comps[e.first] == val and comps[e.second] == val) {
                    E.push_back(e);
                    g.addEdge(e.first, e.second);
                }
            }

            int freq = 0, vert;
            auto adj = g.adj;
            for (int i = 1; i <= N; i++) {
                if (freq < adj[i].size()) {
                    freq = adj[i].size();
                    vert = i;
                }
            }
            bool possible = true;
            for (auto e : E) {
                if (e.first != vert and e.second != vert) {
                    if (uf._find(e.first, e.second)) {
                        possible = false;
                        break;
                    }
                    uf._union(e.first, e.second);
                }
            }

            if (possible) {
                cout << vert << endl;
            } else {
                cout << -1 << endl;
            }

        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}