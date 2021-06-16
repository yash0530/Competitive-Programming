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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int n, m, k;
const int maxN = 505;
int edgesH[maxN][maxN], edgesV[maxN][maxN], vals[maxN][maxN], vals2[maxN][maxN], vals3[maxN][maxN];
int a, b, c, d;
int minVal;

vector<array<int, 2>> dirs = {
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{ -1, 0 }
};

void dfs(int i, int j, int val, int depth) {
	if (depth < a) {
		for (auto d : dirs) {
			int new_i = i + d[0];
			int new_j = j + d[1];
			if ((new_i >= 0) and (new_i < n)) {
				if ((new_j >= 0) and (new_j < m)) {
					if (d[0] == 0) {
						dfs(new_i, new_j, val + edgesH[i][min(new_j, j)], depth + 1);
					}
					else {
						dfs(new_i, new_j, val + edgesV[min(new_i, i)][j], depth + 1);
					}

				}
			}
		}
	} else {
		minVal = min(minVal, val);
	}
}

void dfs2(int i, int j, int val, int depth) {
	if (depth < b) {
		for (auto d : dirs) {
			int new_i = i + d[0];
			int new_j = j + d[1];
			if ((new_i >= 0) and (new_i < n)) {
				if ((new_j >= 0) and (new_j < m)) {
					if (d[0] == 0) {
						dfs2(new_i, new_j, val + edgesH[i][min(new_j, j)], depth + 1);
					}
					else {
						dfs2(new_i, new_j, val + edgesV[min(new_i, i)][j], depth + 1);
					}

				}
			}
		}
	} else {
		minVal = min(minVal, val + vals[i][j]);
	}
}

void dfs3(int i, int j, int val, int depth) {
	if (depth < c) {
		for (auto d : dirs) {
			int new_i = i + d[0];
			int new_j = j + d[1];
			if ((new_i >= 0) and (new_i < n)) {
				if ((new_j >= 0) and (new_j < m)) {
					if (d[0] == 0) {
						dfs3(new_i, new_j, val + edgesH[i][min(new_j, j)], depth + 1);
					}
					else {
						dfs3(new_i, new_j, val + edgesV[min(new_i, i)][j], depth + 1);
					}

				}
			}
		}
	} else {
		minVal = min(minVal, val + vals2[i][j]);
	}
}

void dfs4(int i, int j, int val, int depth) {
	if (depth < d) {
		for (auto d : dirs) {
			int new_i = i + d[0];
			int new_j = j + d[1];
			if ((new_i >= 0) and (new_i < n)) {
				if ((new_j >= 0) and (new_j < m)) {
					if (d[0] == 0) {
						dfs4(new_i, new_j, val + edgesH[i][min(new_j, j)], depth + 1);
					}
					else {
						dfs4(new_i, new_j, val + edgesV[min(new_i, i)][j], depth + 1);
					}

				}
			}
		}
	} else {
		minVal = min(minVal, val + vals3[i][j]);
	}
}

signed main() { fastio;
	cin >> n >> m >> k;
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << -1 << " ";
			} cout << endl;
		}
	} else {
		k /= 2;
		a = min(k, 2LL);
		k -= min(k, 2LL);
		b = min(k, 2LL);
		k -= min(k, 2LL);
		c = min(k, 3LL);
		k -= min(k, 3LL);
		d = min(k, 3LL);
		k -= min(k, 3LL);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (m - 1); j++) {
				cin >> edgesH[i][j];
			}
		}
		for (int i = 0; i < (n - 1); i++) {
			for (int j = 0; j < m; j++) {
				cin >> edgesV[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				minVal = INF;
				dfs(i, j, 0, 0);
				vals[i][j] = minVal;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				minVal = INF;
				dfs2(i, j, 0, 0);
				vals2[i][j] = minVal;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				minVal = INF;
				dfs3(i, j, 0, 0);
				vals3[i][j] = minVal;
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				minVal = INF;
				dfs4(i, j, 0, 0);
				cout << minVal * 2 << " ";				
			} cout << endl;
		}
	}
	return 0;
}