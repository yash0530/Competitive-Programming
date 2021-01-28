#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

struct Edge {
    int v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<vector<int>> dijkstra(int x, vector<vector<Edge>> &adj) {
    int n = size(adj);
    getMat(distance, n + 1, 4, INF);
    getMat(processed, n + 1, 4, 0);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
	distance[x][0] = 0;
	q.push({ 0, x, 0 });
    while (!q.empty()) {
        array<int, 3> ss = q.top(); q.pop();
        int a = ss[1];
        int state = ss[2];
        if (processed[a][state]) continue;
    	processed[a][state] = true;
        for (auto u : adj[a]) {
            int b = u.v, w = u.weight;
            
            // all the edges included
            if (state == 0) {
            	// state -> 0
            	if ((distance[a][0] + w) < distance[b][0]) {
            		distance[b][0] = distance[a][0] + w;
            		q.push({ distance[b][0], b, 0 });
            	}

            	// state -> 1
            	if (distance[a][0] < distance[b][1]) {
            		distance[b][1] = distance[a][0];
            		q.push({ distance[b][1], b, 1 });
            	}

            	// state -> 2
            	if ((distance[a][0] + 2 * w) < distance[b][2]) {
            		distance[b][2] = distance[a][0] + 2 * w;
            		q.push({ distance[b][2], b, 2 });
            	}

            	// state -> 3
            	if ((distance[a][0] + w) < distance[b][3]) {
            		distance[b][3] = distance[a][0] + w;
            		q.push({ distance[b][3], b, 3 });
            	}
            }

            // one edge subracted
            if (state == 1) {
            	// state -> 1
            	if ((distance[a][1] + w) < distance[b][1]) {
            		distance[b][1] = distance[a][1] + w;
            		q.push({ distance[b][1], b, 1 });
            	}

            	// state -> 3
            	if ((distance[a][1] + 2 * w) < distance[b][3]) {
            		distance[b][3] = distance[a][1] + 2 * w;
            		q.push({ distance[b][3], b, 3 });
            	}
            }

            // one edge added
            if (state == 2) {
            	// state -> 2
            	if ((distance[a][2] + w) < distance[b][2]) {
            		distance[b][2] = distance[a][2] + w;
            		q.push({ distance[b][2], b, 2 });
            	}

            	// state -> 3
            	if (distance[a][2] < distance[b][3]) {
            		distance[b][3] = distance[a][2];
            		q.push({ distance[b][3], b, 3 });
            	}
            }

            // one edge subracted and one added
            if (state == 3) {
            	// state -> 3
            	if ((distance[a][3] + w) < distance[b][3]) {
            		distance[b][3] = distance[a][3] + w;
            		q.push({ distance[b][3], b, 3 });
            	}
            }
        }
    }
    return distance;
}

signed main() { fastio;
	int n, m, u, v, w;
	cin >> n >> m;
	vector<vector<Edge>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}
	vector<vector<int>> dist = dijkstra(1, adj);
	for (int i = 2; i <= n; i++) {
		cout << dist[i][3] << " ";
	} cout << endl;
	return 0;
}