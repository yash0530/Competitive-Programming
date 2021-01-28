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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> ss;
		vector<int> a(n);
		for (int i = 1; i <= 2 * n; i++) ss.insert(i);
		for (auto &x : a) {
			cin >> x;
			ss.erase(x);
		}
		sort(_all(a));
		vector<int> b(_all(ss));
		int low = 1, high = n;
		int r1 = 0;
		auto poss1 = [&](int val) {
			for (int i = 0; i < val; i++) {
				if (b[n - val + i] < a[i]) {
					return false;
				}
			}
			return true;
		};
		while (low <= high) {
			int mid = (low + high) / 2;
			if (poss1(mid)) {
				r1 = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		int r2 = 0;
		low = 1, high = n;
		auto poss2 = [&](int val) {
			for (int i = n - val, j = 0; i < n; i++, j++) {
				if (a[i] < b[j]) {
					return false;
				}
			}
			return true;
		};
		while (low <= high) {
			int mid = (low + high) / 2;
			if (poss2(mid)) {
				r2 = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		vector<int> res(n + 1);
		for (int i = n, j = 0; i >= 0 and j <= r1; i--, j++) {
			res[i] = 1;
		}
		for (int i = 0; i <= r2; i++) {
			res[i] += 1;
		}
		int ans = 0;
		for (auto r : res) {
			if (r == 2) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}