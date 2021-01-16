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

signed main() { fastio;
	string s; cin >> s;
	int x, y; cin >> x >> y;
	if (x > y) {
		for (auto &x : s) {
			if (x == '1') x = '0';
			else if (x == '0') x = '1';
		}
		swap(x, y);
	}
	array<int, 2> tot = { 0, 0 }, cnt = { 0, 0 };
	for (auto x : s) if (x != '?') tot[x - '0']++;
	
	int n = size(s);
	vector<array<int, 2>> cost;
	int curr_tot = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			cost.pb({
				(y * cnt[1] + x * (tot[1] - cnt[1])),
				(x * cnt[0] + y * (tot[0] - cnt[0]))
			});
		} else {
			if (s[i] == '0') {
				curr_tot += y * cnt[1];
			} else {
				curr_tot += x * cnt[0];
			}
			cnt[s[i] - '0']++;
		}
	}

	int ans = INF;
	int m = size(cost);
	int cnd = 0;
	for (auto c : cost) cnd += c[1];
	for (int i = 0; i <= m; i++) {
		ans = min(ans, curr_tot + cnd + (i * (m - i) * x));
		if (i < m) {
			cnd -= cost[i][1];
			cnd += cost[i][0];
		}
	}
	cout << ans << endl;
	return 0;
}