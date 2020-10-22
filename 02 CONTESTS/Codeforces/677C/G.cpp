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

struct Edge {
    int v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> dijkstra(int x, int n, vector<vector<Edge>> &adj) {
    vector<int> distance(n + 1);
    vector<bool> processed(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
    }
    distance[x] = 0;
    q.push({ 0, x });
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.v, w = u.weight;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({ distance[b], b });
            }
        }
    }
    return distance;
}

int32_t main() { fastio;
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<Edge>> adj(n + 1);
	int u, v, w;
	vector<pii> edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
		edges.pb({ u, v });
	}
	vector<vector<int>> dists(n + 1);
	for (int i = 1; i <= n; i++) {
		dists[i] = dijkstra(i, n, adj);
	}
	int ans = 0;
	vector<pii> routes(k);
	for (int i = 0; i < k; i++) {
		cin >> routes[i].fs >> routes[i].sc;
		ans += dists[routes[i].fs][routes[i].sc];
	}
	for (auto e : edges) {
		int curr = 0;
		for (auto r : routes) {
			curr += min({ dists[r.fs][r.sc], 
						  dists[r.fs][e.fs] + dists[r.sc][e.sc],
						  dists[r.fs][e.sc] + dists[r.sc][e.fs] });
		}
		ans = min(curr, ans);
	}
	cout << ans << endl;
	return 0;
}