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

int r, g, b;
const int maxN = 205;
int dp[maxN][maxN][maxN];
int a1[maxN], a2[maxN], a3[maxN];

int res(int i, int j, int k) {
	if (i == r) {
		if ((j == g) or (k == b))
			return 0;
	}
	if (j == g and k == b) {
		return 0;
	}

	int &ans = dp[i][j][k];
	if (ans == -1) {
		ans = 0;
		if ((i < r) and (j < g)) {
			ans = res(i + 1, j + 1, k) + a1[i] * a2[j];
		}
		if ((i < r) and (k < b)) {
			ans = max(ans, res(i + 1, j, k + 1) + a1[i] * a3[k]);
		}
		if ((j < g) and (k < b)) {
			ans = max(ans, res(i, j + 1, k + 1) + a2[j] * a3[k]);
		}
	}
	return ans;
}

int32_t main() {
	cin >> r >> g >> b;
	for (int i = 0; i < r; i++) cin >> a1[i];
	for (int i = 0; i < g; i++) cin >> a2[i];
	for (int i = 0; i < b; i++) cin >> a3[i];

	memset(dp, -1, sizeof dp);

	sort(a1, a1 + r, greater<int>());
	sort(a2, a2 + g, greater<int>());
	sort(a3, a3 + b, greater<int>());

	cout << res(0, 0, 0) << endl;

	return 0;
}