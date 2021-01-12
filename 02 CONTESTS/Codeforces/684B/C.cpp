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

vector<vector<char>> mat;

void solve(int a, int b, vector<array<int, 6>> &res) {
	string s;
	s.pb(mat[a][b]);
	s.pb(mat[a][b + 1]);
	s.pb(mat[a + 1][b]);
	s.pb(mat[a + 1][b + 1]);

	if (s == "1111") {
		res.pb({ a, b, a + 1, b, a + 1, b + 1 });
		s = "0100";
	}

	if (s == "0100") {
		res.pb({ a, b + 1, a + 1, b, a + 1, b + 1 });
		s = "0011";
	}

	if (s == "1000") {
		res.pb({ a, b, a + 1, b, a + 1, b + 1 });
		s = "0011";
	}

	if (s == "1001") {
		res.pb({ a, b, a + 1, b, a + 1, b + 1 });
		s = "0010";
	}

	if (s == "0010") {
		res.pb({ a, b, a + 1, b, a, b + 1 });
		s = "1100";
	}

	if (s == "0110") {
		res.pb({ a, b + 1, a + 1, b, a + 1, b + 1 });
		s = "0001";
	}


	if (s == "0001") {
		res.pb({ a, b, a + 1, b + 1, a, b + 1 });
		s = "1100";
	}

	if (s == "1100") {
		res.pb({ a, b, a + 1, b, a + 1, b + 1 });
		s = "0111";
	}

	if (s == "0011") {
		res.pb({ a, b, a, b + 1, a + 1, b + 1 });
		s = "1110";
	}

	if (s == "1010") {
		res.pb({ a, b, a, b + 1, a + 1, b + 1 });
		s = "0111";
	}

	if (s == "0111") {
		res.pb({ a, b + 1, a + 1, b, a + 1, b + 1 });
		s = "0000";
	}

	if (s == "1110") {
		res.pb({ a, b, a + 1, b, a, b + 1 });
		s = "0000";
	}

	if (s == "0101") {
		res.pb({ a, b, a, b + 1, a + 1, b });
		s = "1011";
	}

	if (s == "1011") {
		res.pb({ a, b, a + 1, b, a + 1, b + 1 });
		s = "0000";
	}

	if (s == "1101") {
		res.pb({ a, b, a, b + 1, a + 1, b + 1 });
		s = "0000";
	}

	mat[a][b] = s[0];
	mat[a][b + 1] = s[1];
	mat[a + 1][b] = s[2];
	mat[a + 1][b + 1] = s[3];
}

void apply(array<int, 6> xx) {
	mat[xx[0]][xx[1]] = (!(mat[xx[0]][xx[1]] - '0')) + '0';
	mat[xx[2]][xx[3]] = (!(mat[xx[2]][xx[3]] - '0')) + '0';
	mat[xx[4]][xx[5]] = (!(mat[xx[4]][xx[5]] - '0')) + '0';
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		mat = vector<vector<char>>(n, vector<char>(m));
		for (auto &x : mat) {
			for (auto &y : x) {
				cin >> y;
			}
		}
		vector<array<int, 6>> res;
		if ((n & 1) and (m & 1)) {
			// last row
			for (int i = 0; i < m; i++) {
				if (mat[n - 1][i] == '1') {
					if (i) {
						res.pb({ n - 2, i - 1, n - 2, i, n - 1, i });
						apply(res.back());
					} else {
						res.pb({ n - 2, i, n - 2, i + 1, n - 1, i });
						apply(res.back());
					}
				}
			}

			// last col
			for (int i = 0; i < n - 1; i++) {
				if (mat[i][m - 1] == '1') {
					if (i) {
						res.pb({ i, m - 1, i, m - 2, i - 1, m - 2 });
						apply(res.back());
					} else {
						res.pb({ i, m - 1, i, m - 2, i + 1, m - 2 });
						apply(res.back());
					}
				}
			}
		} else if (n & 1) {
			// last row
			for (int i = 0; i < m; i++) {
				if (mat[n - 1][i] == '1') {
					if (i) {
						res.pb({ n - 2, i - 1, n - 2, i, n - 1, i });
						apply(res.back());
					} else {
						res.pb({ n - 2, i, n - 2, i + 1, n - 1, i });
						apply(res.back());
					}
				}
			}
		} else if (m & 1) {
			// last col
			for (int i = 0; i < n; i++) {
				if (mat[i][m - 1] == '1') {
					if (i) {
						res.pb({ i, m - 1, i, m - 2, i - 1, m - 2 });
						apply(res.back());
					} else {
						res.pb({ i, m - 1, i, m - 2, i + 1, m - 2 });
						apply(res.back());
					}
				}
			}
		}
		for (int i = 0; i < (n - 1); i += 2) {
			for (int j = 0; j < (m - 1); j += 2) {
				solve(i, j, res);
			}
		}
		cout << size(res) << endl;
		for (auto r : res) {
			for (auto x : r) {
				cout << x + 1 << " ";
			} cout << endl;
		}
	}
	return 0;
}