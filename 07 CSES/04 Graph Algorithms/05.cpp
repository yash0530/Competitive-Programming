// CSES Building Teams
#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

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

        void _printColors() {
        	for (int i = 1; i < vertices; i++) {
        		cout << color[i] + 1 << " ";
        	} cout << endl;
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

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	Graph G(n);
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		G._addEdge(a, b);
	}
	if (G._isBipartite()) {
		G._printColors();
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}