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

int n, k;
const int maxN = 2e5 + 5;
vector<vector<int>> verts(maxN);

struct comp {
	bool operator()(const int &a, const int &b) {
		if (size(verts[a]) == size(verts[b])) return a < b;
		return size(verts[a]) > size(verts[b]);
	}	
};

int32_t main() {
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> n >> k;

		set<int> adj[n + 5];
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			adj[x].insert(y);
			adj[y].insert(x);
		}

		if (k == 1) {
			cout << n - 1 << endl;
			continue;
		}

		for (int i = 1; i <= n; i++) verts[i].clear();
		for (int i = 1; i <= n; i++) {
			if (size(adj[i]) == 1) {
				verts[*adj[i].begin()].pb(i);
			}
		}
		
		set<int, comp> PQ;
		for (int i = 1; i <= n; i++) {
			if (size(verts[i])) {
				PQ.insert(i);
			}
		}

		int res = 0;
		while (!PQ.empty()) {
			int tp = *PQ.begin();
			PQ.erase(PQ.begin());
			if (size(verts[tp]) < k) {
				break;
			}
			res++;
			for (int i = 0; i < k; i++) {
				int val = verts[tp].back();
				adj[val].erase(tp);
				adj[tp].erase(val);
				verts[tp].pop_back();
			}
			if (size(verts[tp]) > 0) {
				PQ.insert(tp);
			} else {
				if (size(adj[tp]) == 1) {
					int vert = *adj[tp].begin();
					PQ.erase(vert);
					verts[vert].pb(tp);
					PQ.insert(vert);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}