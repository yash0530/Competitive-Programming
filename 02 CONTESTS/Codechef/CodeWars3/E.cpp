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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n, m, u, q;
	cin >> n >> m >> u >> q;
	getMat(mat, n + 5, m + 5, 0);
	getMat(upds, n + 5, m + 5, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	int val, r1, c1, r2, c2;
	while (u--) {
		cin >> val >> r1 >> c1 >> r2 >> c2;
		r1++; r2++; c1++; c2++;
		upds[r1][c1] += val;
		upds[r2 + 1][c1] += -val;
		upds[r1][c2 + 1] += -val;
		upds[r2 + 1][c2 + 1] += val;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			upds[i][j] = upds[i - 1][j] + upds[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			upds[i][j] = upds[i][j - 1] + upds[i][j];
			mat[i][j] += upds[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = mat[i - 1][j] + mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = mat[i][j - 1] + mat[i][j];
		}
	}
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1++; r2++; c1++; c2++;
		cout << mat[r2][c2] + mat[r1 - 1][c1 - 1] - mat[r2][c1 - 1] - mat[r1 - 1][c2] << endl;
	}
	return 0;
}
