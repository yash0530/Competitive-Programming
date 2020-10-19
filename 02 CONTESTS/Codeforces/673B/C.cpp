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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) cin >> a;
		vector<vector<int>> okays(n + 1, { 0, n + 1 });
		for (int i = 1; i <= n; i++) {
			okays[arr[i - 1]].pb(i);
		}
		for (auto &okay : okays) {
			sort(okay.begin(), okay.end());
		}
		vector<int> res(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			int mx = 0;
			int prev = okays[i][0];
			for (int j = 1; j < size(okays[i]); j++) {
				int curr = okays[i][j] - prev;
				prev = okays[i][j];
				mx = max(curr, mx);
			}
			if (mx <= n) {
				if (res[mx] == -1) {
					res[mx] = i;
				}
			}
		}
		int prev = INF;
		for (int i = 1; i <= n; i++) {
			if (res[i] == -1 and prev == INF) {
				cout << -1 << " ";
				continue;
			}
			if (res[i] == -1) {
				res[i] = prev;
			}
			res[i] = min(prev, res[i]);
			cout << res[i] << " ";
			prev = res[i];
		} cout << endl;
	}
	return 0;
}