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
		int n, m;
		cin >> n >> m;
		vector<string> mat(n);
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}
		bool poss = true;
		if (mat[n - 1][m - 1] == 'B') {
			poss = false;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'G') {
					count++;
				}
 				if (mat[i][j] == 'B') {
					if (i) {
						if (mat[i - 1][j] == 'G') {
							poss = false;
						} else if (mat[i - 1][j] != 'B')
						mat[i - 1][j] = '#';
					}
					if (j) {
						if (mat[i][j - 1] == 'G') {
							poss = false;
						} else if (mat[i][j - 1] != 'B')
						mat[i][j - 1] = '#';
					}
					if (i != n - 1) {
						if (mat[i + 1][j] == 'G') {
							poss = false;
						} else if (mat[i + 1][j] != 'B')
						mat[i + 1][j] = '#';
					}
					if (j != m - 1) {
						if (mat[i][j + 1] == 'G') {
							poss = false;
						} else if (mat[i][j + 1] != 'B')
						mat[i][j + 1] = '#';
					}
				}
			}
		}
		if ((count == 0) and (mat[n - 1][m - 1] != 'B')) {
			cout << "Yes" << endl;
			continue;
		}
		if (mat[n - 1][m - 1] == '#') {
			poss = false;
		}
		queue<pii> Q;
		getMat(vis, n, m, 0);
		Q.push({ n - 1, m - 1 });
		vis[n - 1][m - 1] = true;
		while (!Q.empty()) {
			int i = Q.front().fs;
			int j = Q.front().sc;
			Q.pop();
			if (i) {
				if ((vis[i - 1][j] == false) and (mat[i - 1][j] != '#')) {
					vis[i - 1][j] = true;
					Q.push({ i - 1, j });
				}
			}
			if (j) {
				if ((vis[i][j - 1] == false) and (mat[i][j - 1] != '#')) {
					vis[i][j - 1] = true;
					Q.push({ i, j - 1 });
				}
			}
			if (i != n - 1) {
				if ((vis[i + 1][j] == false) and (mat[i + 1][j] != '#')) {
					vis[i + 1][j] = true;
					Q.push({ i + 1, j });
				}
			}
			if (j != m - 1) {
				if ((vis[i][j + 1] == false) and (mat[i][j + 1] != '#')) {
					vis[i][j + 1] = true;
					Q.push({ i, j + 1 });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'G' and !vis[i][j]) {
					poss = false;
				}
			}
		}
		if (poss) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
