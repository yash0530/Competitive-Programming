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

int n;
const int maxN = 5e5 + 5;
bool added[maxN], marked[maxN];
vector<int> adj[maxN];

bool dfs(int root = 1, int parent = -1) {
	bool poss = true;
	for (auto x : adj[root]) {
		if (x != parent) {
			if (marked[x]) {
				return false;
			}
			marked[x] = true;
			poss = poss & dfs(x, root);
		}
	}
	return poss;
}

int32_t main() { fastio;
    
    cin >> n;
	pair<int, int> events[2 * n];
	pair<int, int> arr[n + 1];
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i + 1] = { a, b };
		events[i] = { b, i + 1};
		events[i + n] = { a, i + 1};
	}
	sort(events, events + 2 * n);

	set<pair<int, int>> evs;
	int total = 0;
	for (auto e : events) {
		if (added[e.second]) {
			evs.erase({ arr[e.second].first, e.second });
		} else {
			added[e.second] = true;
			for (auto x : evs) {
				if (arr[x.second].second <= arr[e.second].second) {
					adj[x.second].push_back(e.second);
					adj[e.second].push_back(x.second);
					total++;
					if (total == n) {
						cout << "NO" << endl;
						return 0;
					}	
				}
			}
			evs.insert(e);
		}
	}
	marked[1] = true;
	if (total == n - 1 and dfs()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
    return 0;
}
