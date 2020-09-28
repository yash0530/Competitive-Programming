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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int ld = 0, rd = n * (n - 1) / 2;
		for (int i = 1, cd = 0; i <= n; ++i) {
			if (!(i & (i - 1))) ++cd;
			ld += cd - 1;
		}
		if (!(ld <= d && d <= rd)) {
			cout << "NO" << endl;
			continue;
		}
		vector<int> res(n + 1);
		vector<set<int>> heights(n + 1);
		vector<int> node_height(n + 1);
		vector<int> subtree(n + 1);
		subtree[1] = 1;
		node_height[1] = 0;
		heights[0].insert(1);
		for (int i = 2; i <= n; i++) {
			res[i] = i - 1;
			heights[i - 1].insert(i);
			node_height[i] = i - 1;
			subtree[i] = 1;
		}
		subtree[n] = 0;
		int curr = ((n - 1) * n) / 2;
		bool poss = true;
		priority_queue<pii, vector<pii>, greater<pii>> leaves; leaves.push({ n - 1, n });
		while (curr != d) {
			if (leaves.empty()) {
				poss = false;
				break;
			}
			int leaf = leaves.top().sc; leaves.pop();
			int leaf_height = node_height[leaf];
			if ((leaf_height - 2) >= 0) {
				if (!heights[leaf_height - 2].empty()) {
					int new_parent = *heights[leaf_height - 2].begin();
					heights[leaf_height - 2].erase(heights[leaf_height - 2].begin());

					int curr_parent = res[leaf];
					subtree[curr_parent]--;
					if (subtree[curr_parent] == 1) {
						heights[node_height[curr_parent]].insert(curr_parent);
					}

					if (subtree[curr_parent] == 0) {
						leaves.push({ node_height[curr_parent], curr_parent });
					}

					subtree[new_parent]++;
					if (subtree[new_parent] == 1) {
						heights[node_height[new_parent]].insert(new_parent);
					}
					heights[leaf_height].erase(leaf);
					heights[leaf_height - 1].insert(leaf);

					res[leaf] = new_parent;
					node_height[leaf] = leaf_height - 1;
					leaves.push({ leaf_height - 1, leaf });
					curr--;
				}
			}
		}
		if (poss) {
			cout << "YES" << endl;
			for (int i = 2; i <= n; i++) {
				cout << res[i] << " ";
			} cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}