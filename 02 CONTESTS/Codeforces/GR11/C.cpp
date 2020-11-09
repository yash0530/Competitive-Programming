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

int32_t main() { fastio;
	int r, n;
	cin >> r >> n;
	vector<array<int, 3>> celebs(n);
	for (auto &c : celebs) cin >> c[0] >> c[1] >> c[2];
	vector<int> dp(n, -INF), pref(n, -INF);
	for (int i = 0; i < n; i++) {
		if ((celebs[i][1] + celebs[i][2] - 2) <= celebs[i][0]) {
			dp[i] = 1;
			if ((i - 2 * r) >= 0) {
				dp[i] = max(dp[i], 1 + pref[i - 2 * r]);
			}
			for (int j = i - 1; j > (i - 2 * r) and j >= 0; j--) {
				if ((abs(celebs[i][1] - celebs[j][1]) + abs(celebs[i][2] - celebs[j][2])) <= (celebs[i][0] - celebs[j][0])) {
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
			if (i) {
				pref[i] = max(dp[i], pref[i - 1]);
			} else {
				pref[i] = dp[i];
			}
		}
	}
	cout << max(0LL, *max_element(_all(dp))) << endl;
	return 0;
}