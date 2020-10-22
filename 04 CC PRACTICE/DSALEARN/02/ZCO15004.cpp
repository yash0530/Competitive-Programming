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
	int n; cin >> n;
	vector<pii> pairs(n), rev_p;
	for (auto &p : pairs) {
		cin >> p.fs >> p.sc;
		rev_p.pb({ p.sc, p.fs });
	}
	pairs.pb({ 0, 500 });
	pairs.pb({ 100000, 500 });
	sort(pairs.begin(), pairs.end());
	sort(rev_p.begin(), rev_p.end());
	int ans = 0;
	n += 2;
	for (int i = 1; i < n; i++) {
		ans = max(ans, (pairs[i].fs - pairs[i - 1].fs) * 500);
	}	
	set<int> points, to_add; int prev = rev_p[0].fs;
	for (auto pp : rev_p) {
		if (prev < pp.fs) {
			prev = pp.fs;
			for (auto x : to_add) {
				points.insert(x);
			}
			to_add.clear();
		}
		pii p = { pp.sc, pp.fs };
		int lw = 0, hg = 100000;
		bool found = false;
		if (p.fs and p.fs != 100000) {
			auto hh = points.upper_bound(p.fs);
			if (hh != points.end()) {
				hg = min(hg, *hh);	
			}
			auto ll = points.lower_bound(p.fs);
			if (ll != points.begin()) {
				ll--;
				lw = max(*ll, lw);
			}
			if (!found and points.find(p.fs) != points.end()) {
				found = true;
			}
			if (found) {
				ans = max(ans, (p.fs - lw) * p.sc);
				ans = max(ans, (hg - p.fs) * p.sc);
			} else {
				ans = max(ans, (hg - lw) * p.sc);
			}
			to_add.insert(p.fs);
		}
	}
	cout << ans << endl;
	return 0;
}