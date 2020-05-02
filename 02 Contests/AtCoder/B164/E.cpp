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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)

vector<vector<int>> PATHS;

class Graph { 
    int V;
    list<int> *adj;
    void printAllPathsUtil(int u, int d, bool visited[], int path[], int &path_index) { 
	    visited[u] = true; 
	    path[path_index] = u; 
	    path_index++;
	    if (u == d) { 
	    	vector<int> temp;
	        for (int i = 0; i < path_index; i++) 
	            temp.pb(path[i]); 
	        PATHS.pb(temp);
	    } 
	    else {
	        list<int>::iterator i; 
	        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	            if (!visited[*i]) 
	                printAllPathsUtil(*i, d, visited, path, path_index); 
	    } 
	    path_index--; 
	    visited[u] = false; 
	} 
  
	public: 
	    Graph(int V) { 
		    this->V = V; 
		    adj = new list<int>[V]; 
		} 
	    
	    void addEdge(int u, int v) { 
		    adj[u].push_back(v);
		    adj[v].push_back(u);
		} 

	    void printAllPaths(int s, int d) { 
	    	PATHS.clear();
			bool *visited = new bool[V]; 

			int *path = new int[V]; 
			int path_index = 0;

			for (int i = 0; i < V; i++) 
			    visited[i] = false; 

			printAllPathsUtil(s, d, visited, path, path_index); 
		}
}; 

map<pair<int, int>, pair<int, int>> ps;
vector<pii> cities(55);
int s;

int eval(int pos, vector<int> path) {
	int n = size(path);
	vector<int> prefMin(n), prefCoin(n);
	for (int i= 1; i < n; i++) {
		prefMin[i] = prefMin[i - 1] + ps[{ path[i - 1], path[i] }].sc;
	}
	for (int i = 1; i < n; i++) {
		prefCoin[i] = prefCoin[i - 1] + ps[{ path[i - 1], path[i] }].fs;
	}
	vector<int> vls(n);
	int reqd = prefCoin.back();
	for (int i = 1; i < n; i++) {
		vls[i] = INF;
		for (int j = 0; j < i; j++) {
			int val;
			if (j == 0) {
				val = 0;
			} else {
				val = vls[j - 1];
			}
			
		}
	}
	return vls.back() + prefMin.back();
}

int32_t main() { fastio;
	int n, m;
	cin >> n >> m >> s;

	Graph G(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		ps[{ u, v }] = { a, b };
		ps[{ v, u }] = { a, b };
		G.addEdge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		cin >> cities[i].fs >> cities[i].sc;
	}

	for (int i = 2; i <= n; i++) {
		int res = INF;
		G.printAllPaths(1, i);
		for (auto p : PATHS) {
			res = min(res, eval(0, p));
		}
		cout << res << endl;
	}

	return 0;
}
