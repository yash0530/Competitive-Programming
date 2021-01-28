#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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
#define add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int n; cin >> n;
	array<int, 2> sum = { 0, 0 };
	vector<int> dp(n + 5);
	dp[0] = 1; dp[1] = inv(2); dp[2] = inv(4);
	sum[0] = inv(2);
	sum[1] = dp[1];
	for (int i = 3; i <= n; i++) {
		if (i & 1) {
			dp[i] = mul(sum[0], inv(2));
			sum[1] = add(mul(sum[1], inv(4)), dp[i]);
		} else {
			dp[i] = mul(sum[1], inv(2));
			sum[0] = add(mul(sum[0], inv(4)), dp[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}