// CSES Edit Distance
#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

int n, m;
string a, b;
const int maxN = 5e3 + 5;
int dp[maxN][maxN];

int res(int p1, int p2) {
	if (p1 == n and p2 == m) return 0;
	int &ans = dp[p1][p2];
	if (ans == -1) {
		ans = INT_MAX;
		if (p1 == n) {
			ans = res(p1, p2 + 1) + 1;
		} else if (p2 == m) {
			ans = res(p1 + 1, p2) + 1;
		} else if (a[p1] == b[p2]) {
			ans = res(p1 + 1, p2 + 1);
		} else {
			ans = min({ res(p1, p2 + 1) + 1, res(p1 + 1, p2) + 1, res(p1 + 1, p2 + 1) + 1 });
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> a >> b;
	n = size(a); m = size(b);
	memset(dp, -1, sizeof dp);
	cout << res(0, 0) << endl;
	return 0;
}