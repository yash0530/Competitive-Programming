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
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

bool overlap(vector<int> a, vector<int> b) {
	if ((a[1] > b[0]) and (a[0] <= b[0])) {
		return true;
	} else if ((b[1] > a[0]) and (b[0] <= a[0])) {
		return true;
	} else if ((a[0] < b[0]) and (a[1] > b[1])) {
		return true;
	} else if ((b[0] < a[0]) and (b[1] > a[1])) {
		return true;
	} else if ((a[0] == b[0]) and (a[1] == b[1])) {
		return true;
	}
	return false;
}

class Graph {
    private:
        int vertices;
        vector<int> *adj;
        vector<int> color;
        vector<bool> marked;
        bool isBipartite;
 
    public:
        Graph(int V) {
            vertices = V;
            adj = new vector<int>[vertices];
        }
 
        void _addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
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
            for (int i = 0; i < vertices; i++) {
                if (!marked[i])
                    _breadthFirstSearch(i, 0);
                if (!isBipartite) break;
            }
            if (isBipartite) {
            	for (auto c : color) {
            		if (c) cout << 'J';
            		else cout << 'C';
            	} cout << endl;
            }
            return isBipartite;
        }
};

int32_t main() { fastio;
    int t; cin >> t;
    for (int _ = 1; _ <= t; _++) {
    	cout << "Case #" << _ << ": ";
		int u, v;
    	int n; cin >> n;
    	vector<vector<int>> acts(n);
    	for (int i = 0; i < n; i++) {
    		cin >> u >> v;
    		acts[i] = { u, v, i };
    	}

    	Graph G(n);
    	for (int i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			if (overlap(acts[i], acts[j])) {
    				G._addEdge(acts[i][2], acts[j][2]);
    			}
    		}
     	}

     	if (!G._isBipartite()) {
     		cout << "IMPOSSIBLE" << endl;
     	}
    }
    return 0;
}
