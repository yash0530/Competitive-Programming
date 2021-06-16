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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		vector<int> pref(n);
		pref[0] = arr[0];
		vector<int> res = { pref[0] };
		vector<int> indices = { 0 };
		for (int i = 1; i < n; i++) {
			pref[i] = arr[i] + pref[i - 1];
			if (pref[i] > res.back()) {
				res.pb(pref[i]);
				indices.pb(i);
			}
		}
		int sum = pref.back();
		while (m--) {
			int x; cin >> x;
			if (sum > 0) {
				auto loc = lower_bound(_all(res), x) - res.begin();
				if (loc == size(res)) {
					int ans, low = 1, high = 2e9;
					while (low <= high) {
						int mid = (low + high) / 2;
						auto loc = lower_bound(_all(res), x - mid * sum) - res.begin();
						if (loc == size(res)) {
							low = mid + 1;
						} else {
							high = mid - 1;
							ans = n * mid + indices[loc];
						}
					}
					cout << ans << " ";
				} else {
					cout << indices[loc] << " ";
				}
			} else {
				auto loc = lower_bound(_all(res), x) - res.begin();
				if (loc == size(res)) {
					cout << -1 << " ";
				} else {
					cout << indices[loc] << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}