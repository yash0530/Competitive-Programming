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

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		array<pii, 4> points;
		for (int i = 0; i < 4; i++) {
			cin >> points[i].fs >> points[i].sc;
		}
		auto eval = [&](int mid) {
			array<int, 4> x, y;
			x[0] = points[0].fs;
			x[1] = points[1].fs - mid;
			x[2] = points[2].fs;
			x[3] = points[3].fs - mid;

			y[0] = points[0].sc;
			y[1] = points[1].sc;
			y[2] = points[2].sc - mid;
			y[3] = points[3].sc - mid;

			sort(_all(x));
			sort(_all(y));

			int64_t val = 0;
			for (int i = 0; i < 4; i++) {
				val += abs(x[i] - x[1]) + abs(y[i] - y[1]);
			}
			return val;
		};
		int64_t ans = INT_MAX;
		array<pii, 4> org_points = points;
		array<int, 4> perm = { 0, 1, 2, 3 };
		do {
			for (int i = 0; i < 4; i++) {
				points[i] = org_points[perm[i]];
			}
			int low = 0, high = 2e9 + 10;
			while (low < high) {
				int64_t mid = (low + high) / 2;
				if (eval(mid) < eval(mid + 1)) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			ans = min(ans, eval(low));
		} while (next_permutation(_all(perm)));
		cout << ans << endl;
	}
	return 0;
}