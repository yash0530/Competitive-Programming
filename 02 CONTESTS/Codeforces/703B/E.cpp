#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF INT_MAX
#define HELL (int) (1e9 + 7)
// #define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

struct Edge {
    int v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> dijkstra(int x, vector<vector<Edge>> &adj) {
    int n = size(adj) - 1;
    int distance[n + 1][52];
    bool processed[n + 1][52];
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j < 52; j++) {
	        distance[i][j] = INF;
    		processed[i][j] = 0;
    	}
    }

    // { dist, vertex, last_w }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

    pq.push({ 0, x, 0 });
    distance[x][0] = 0;

    while (!pq.empty()) {
    	array<int, 3> curr = pq.top(); pq.pop();
    	int dist = curr[0];
        int vert = curr[1];
        int last_w = curr[2];

        if (processed[vert][last_w]) continue;
        processed[vert][last_w] = true;
        
        for (auto u : adj[vert]) {
            int b = u.v, w = u.weight;
       	
            if (last_w == 0) {
            	if (distance[b][w] > distance[vert][last_w]) {
	            	distance[b][w] = distance[vert][last_w];
	            	pq.push({ distance[b][w], b, w });
            	}
            } else {
            	int W = (last_w + w) * (last_w + w);
            	if (distance[vert][last_w] + W < distance[b][0]) {
            		distance[b][0] = distance[vert][last_w] + W;
	            	pq.push({ distance[b][0], b, 0 });
            	}
            }
        }
    }
    vector<int> dist(n + 1);
    for (int i = 1; i <= n; i++) {
    	dist[i] = distance[i][0] == INF ? -1 : distance[i][0];
    }
    return dist;
}

signed main() { fastio;
	int n, m; cin >> n >> m;
	vector<vector<Edge>> adj(n + 1);
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}
	auto d = dijkstra(1, adj);
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	return 0;
}