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

vector<array<int, 2>> dirs = {
	{ 1, 1 },
	{ 0, 1 },
	{ -1, 0 },
	{ -1, -1 },
	{ 0, -1 },
	{ 1, 0 }
};
int costs[6];

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < 6; i++) {
			cin >> costs[i];
		}

		// normalize costs
		getMat(norm_costs, 22, 22, INF);
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> Q;
		Q.push({ 0, 0, 0 });
		while (!Q.empty()) {
			auto tp = Q.top(); Q.pop();
			int val = norm_costs[tp[1] + 10][tp[2] + 10];
			norm_costs[tp[1] + 10][tp[2] + 10] = min(norm_costs[tp[1] + 10][tp[2] + 10], tp[0]);
			if (val == INF) {
				for (int i = 0; i < 6; i++) {
					int nwx = tp[1] + dirs[i][0];
					int nwy = tp[2] + dirs[i][1];
					if (abs(nwx) < 5 and abs(nwy) < 5) {
						if (norm_costs[nwx + 10][nwy + 10] == INF) {
							Q.push({ tp[0] + costs[i], nwx, nwy });
						}
					}
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			costs[i] = min(costs[i], norm_costs[dirs[i][0] + 10][dirs[i][1] + 10]);
		}

		vector<int> perm = { 0, 1, 2, 3, 4, 5 };
		int val = INF;
		do {
			int ans = 0;
			int curr_x = 0, curr_y = 0;
			for (auto p : perm) {
				auto dir = dirs[p];
				int a = x - curr_x;
				int b = y - curr_y;
				int v1 = INF, v2 = INF;
				if (dir[0]) {
					if (a > 0 and dir[0] > 0) {
						v1 = a;
					} else if (a < 0 and dir[0] < 0) {
						v1 = abs(a);
					} else {
						v1 = 0;
					}
				}
				if (dir[1]) {
					if (b > 0 and dir[1] > 0) {
						v2 = b;
					} else if (b < 0 and dir[1] < 0) {
						v2 = abs(b);
					} else {
						v2 = 0;
					}
				}
				int final = min(v1, v2);
				ans += (costs[p] * final);
				curr_x += final * dir[0];
				curr_y += final * dir[1];
			}
			if (curr_x == x and curr_y == y) {
				val = min(val, ans);
			}
	    } while (next_permutation(perm.begin(), perm.end())); 
		cout << val << endl;
	}
	return 0;
}
