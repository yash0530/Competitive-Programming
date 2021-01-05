#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

int n, x;
const int maxN = 5e3 + 5;
int dp[maxN][maxN], cache[maxN][maxN], arr[maxN];

int count(int b, int a, int val) {
	return cache[b][val] - cache[a - 1][val];
}

int res(int pos, int prev) {
	if (pos > n) {
		return 0;
	}
	int &ans = dp[pos][prev];
	if (ans == -1) {
		ans = 0;
		int tt = count(pos, prev, arr[pos]);
		if (tt == 2) {
			ans = max(ans, res(pos + 1, pos + 1) - x + 1);
			ans = max(ans, res(pos + 1, prev) - 1);
		} else if (tt > 2) { 
			ans = max(ans, res(pos + 1, pos + 1) - x + 1);
			ans = max(ans, res(pos + 1, prev));
		} else {
			ans = max(ans, res(pos + 1, prev) + 1);
		}
	}
	return ans;
}

signed main() { fastio;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) {
		cache[i][arr[i]] = 1;
		for (int j = 1; j <= 1000; j++) {
			cache[i][j] += cache[i - 1][j];
		}
	}
	cout << max(res(1, 1) - x, 0) << endl;
	return 0;
}