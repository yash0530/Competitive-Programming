#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb emplace_back
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

int n;
const int maxN = 2005;
pii dp[maxN][maxN];

pii res(int ind = 0, int bal = 0) {
	if (((n - ind) < bal) or (bal < 0)) {
		return { 0, false };
	}
	if (ind == n) {
		return { 0, false };
	}
	if (dp[ind][bal].fs != -1) {
		return dp[ind][bal];
	}
	pii a = res(ind + 1, bal + 1);
	pii b = res(ind + 1, bal - 1);
	if (!a.sc and !b.sc) {
		dp[ind][bal] = { (a.fs + b.fs + 1) % HELL, true };
	} else {
		dp[ind][bal] = { (a.fs + b.fs) % HELL, false };
	}
	return dp[ind][bal];
}

int32_t main() { fastio;
	cin >> n; n <<= 1;
	memset(dp, -1, sizeof dp);
	cout << res().first << endl;
	return 0;
}
