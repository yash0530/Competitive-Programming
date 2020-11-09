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
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> robs(n), lights(m);
	for (auto &r : robs) cin >> r[0] >> r[1];
	for (auto &l : lights) cin >> l[0] >> l[1];
	vector<array<int, 2>> okays;
	for (auto r : robs) {
		for (auto l : lights) {
			okays.pb({ max(l[0] - r[0] + 1, 0LL), max(l[1] - r[1] + 1, 0LL) });
		}
	}
	sort(okays.begin(), okays.end(), greater<array<int, 2>>());
	vector<int> r(1e6 + 5);
	int pref = 0;
	for (auto x : okays) {
		pref = max(pref, x[1]);
		if (x[0] - 1 >= 0)
			r[x[0] - 1] = max(r[x[0] - 1], pref);
	}
	int ans = INF;
	for (int i = 1e6 + 1; i >= 0; i--) {
		r[i] = max(r[i], r[i + 1]);
		ans = min(ans, i + r[i]);
	}
	cout << ans << endl;
	return 0;
}