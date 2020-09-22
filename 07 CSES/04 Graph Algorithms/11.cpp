// CSES Flight Discount
#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 1e16
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
	vector<vector<int>> edges;
	int n, m;
	cin >> n >> m;
	vector<vector<Edge>> adj(n + 1);
	vector<vector<Edge>> radj(n + 1);
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].pb({ b, w });
		radj[b].pb({ a, w });
		edges.pb({ a, b, w });
	}
	auto distA = dijkstra(1, n, adj);
	auto distB = dijkstra(n, n, radj);
	int res = distA[n];
	for (auto e : edges) {
		res = min(res, distA[e[0]] + distB[e[1]] + e[2] / 2);
	}
	cout << res << endl;
	return 0;
}