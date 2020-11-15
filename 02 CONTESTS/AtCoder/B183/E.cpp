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
#define add(a, b) (a % HELL + b % HELL) % HELL

signed main() { fastio;
	int n, m;
	cin >> n >> m;
	vector<string> mat(n);
	for (auto &x : mat) cin >> x;
	getMat(dp, n, m, 0);
	dp[0][0] = 1;
	map<int, int> rows, cols, diags;
	rows[0] = 1, cols[0] = 1, diags[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j) {
				if (mat[i][j] == '#') {
					rows[i] = 0;
				} else {
					dp[i][j] = add(dp[i][j], rows[i]);
				}
			}
			if (i) {
				if (mat[i][j] == '#') {
					cols[j] = 0;
				} else {
					dp[i][j] = add(dp[i][j], cols[j]);
				}
			}
			if (i and j) {
				if (mat[i][j] == '#') {
					diags[i - j] = 0;
				} else {
					dp[i][j] = add(dp[i][j], diags[i - j]);
				}
			}
			if (mat[i][j] == '.') {
				rows[i] = add(rows[i], dp[i][j]);
				cols[j] = add(cols[j], dp[i][j]);
				diags[i - j] = add(diags[i - j], dp[i][j]);
			}
		}
	}
	cout << mul(dp[n - 1][m - 1], inv(2)) << endl;
	return 0;
}