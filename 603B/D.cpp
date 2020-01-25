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
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

class Graph {
    private:
        vector<set<int>> adj;
        vector<bool> marked;
        int vertices;

        void __dfs(int s) {
            for (auto x : adj[s]) {
                if (!marked[x]) {
                    marked[x] = true;
                    __dfs(x);
                } 
            }
        }
        
    public:
        Graph(int n) {
            vertices = n;
            adj = vector<set<int>>(vertices);
        }
        
        void _addEdge(int u, int v) {
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int _getConnectedComps() {
            marked.assign(vertices, 0);
            int count = 0;
            for (int i = 0; i < vertices; i++) {
                if (!marked[i]) {
                    count++;
                    marked[i] = true;
                    __dfs(i);
                }
            }
            return count;
        }
};

int32_t main() { fastio;
    int n; cin >> n;
    Graph G(n);
    vector<string> arr(n);
    vector<vector<int>> alpha(128);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (auto x : arr[i]) {
            if (alpha[x].size() != 0) {
                G._addEdge(i, alpha[x][0]);
            }
            alpha[x].push_back(i);
        }
    }
    cout << G._getConnectedComps() << endl;
    return 0;
}