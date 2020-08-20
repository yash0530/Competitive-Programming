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

int timer = 0;
int n, m;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];

bool cycleDFS(int v, vector<bool> &visited, vector<bool> &recStack) { 
    if(!visited[v]) {
        visited[v] = true; 
        recStack[v] = true;
        for(auto a : adj[v]) { 
            if (!visited[a] and cycleDFS(a, visited, recStack)) {
                return true; 
            }
            else if (recStack[a]) {
                return true; 
            }
        }
    }
    recStack[v] = false;
    return false; 
}

bool hasCycle() {
	vector<bool> visited(n + 5), recStack(n + 5);
    for(int i = 1; i <= n; i++) {
        if (cycleDFS(i, visited, recStack)) {
            return true; 
        }
    }
    return false; 
}

void topoDFS(int v, vector<bool> &visited, vector<int> &res) {
    visited[v] = true;
    for (auto a : adj[v]) {
        if (!visited[a]) {
            topoDFS(a, visited, res); 
        }
    }
    res.pb(v);
}

vector<int> topoSort() {
    vector<int> res; 
    vector<bool> visited(n + 5);
    for (int i = 1; i <= n; i++) { 
		if (!visited[i]) { 
			topoDFS(i, visited, res); 
    	}
    }
    reverse(res.begin(), res.end());
    return res;
}

int32_t main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<pii> edges;
		vector<pii> e2s;

		timer = 0;
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
		}

		int a, x, y;
		for (int i = 0; i < m; i++) {
			cin >> a >> x >> y;
			if (a) {
				adj[x].pb(y);
				e2s.pb({ x, y });
			} else {
				edges.pb({ x, y });
			}
		}

		if (hasCycle()) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			vector<int> topo = topoSort();
			vector<int> pos(n + 1);
			for (int i = 0; i < n; i++) {
				pos[topo[i]] = i;
			}
			for (auto e : edges) {
				if (pos[e.fs] < pos[e.sc]) {
					cout << e.fs << " " << e.sc << endl;
				} else {
					cout << e.sc << " " << e.fs << endl;
				}
			}
			for (auto e : e2s) {
				cout << e.fs << " " << e.sc << endl;
			}
		}
	}
	return 0;
}