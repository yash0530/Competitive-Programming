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

int n, m, k;
const int maxN = 505;
vector<vector<int>> days(maxN);
vector<vector<int>> removed_day(maxN);
int dp[maxN][maxN];

int res(int pos, int rem) {
	if (pos == n) {
		return 0;
	}
	int &ans = dp[pos][rem];
	if (ans == -1) {
		ans = INF;
		for (int i = 0; i <= rem; i++) {
			ans = min(ans, removed_day[pos][i] + res(pos + 1, rem - i));
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n >> m >> k;
	memset(dp, -1, sizeof dp);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				days[i].pb(j);
			}
		}
		for (int z = 0; z <= k; z++) {
			if (size(days[i]) <= z) {
				removed_day[i].pb(0);
			} else {
				if (z == 0) {
					removed_day[i].pb(days[i].back() - days[i][0] + 1);
				} else {
					int val = INF;
					for (int c = 0; c < z + 1; c++) {
						val = min(val, days[i][size(days[i]) - 1 - z + c] - days[i][c] + 1);
					}
					removed_day[i].pb(val);
				}
			}
		}
	}
	cout << res(0, k);
	return 0;
}