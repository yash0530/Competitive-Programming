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

const int maxN = 75;
int n, m, k, mx;
int mat[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];

int res(int row, int col, int used, int remainder) {
	if (row == n) {
		if (remainder) return -INF;
		return 0;
	}
	int &ans = dp[row][col][used][remainder];
	if (ans == -1) {
		if (col == m) {
			ans = res(row + 1, 0, 0, remainder);
		} else {
			ans = res(row, col + 1, used, remainder);
			if (used < mx) {
				ans = max(ans, mat[row][col] + res(row, col + 1, used + 1, (remainder + mat[row][col]) % k));
			} 
		}
	}
	return ans;
}

signed main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	mx = (m / 2);
	deb(mx);
	memset(dp, -1, sizeof dp);
	cout << res(0, 0, 0, 0) << endl;
	return 0;
}