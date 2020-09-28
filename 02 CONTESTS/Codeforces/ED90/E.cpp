#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int genPref(int val) {
	if (val <= 8) return val;
	int ans = 8;
	val -= 8;
	int base = 10;
	while (val) {
		if (val >= 9) {
			ans += base * 9;
			val -= 9;
		} else {
			ans += base * val;
			val = 0;
		}
		base *= 10;
	}
	return ans;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int base = 1, ans = INF;
		for (int nines = 0; nines < 17; nines++) {
			base *= 10;
			for (int last = 0; last < 10; last++) {
				int t1 = min(10 - last, k + 1);
				int t2 = k + 1 - t1;
				int summ = 0;
				for (int d = last, j = 0; j <= k; j++, d++) {
					summ += (d % 10);
				}
				int reqd = n - summ - t2 - nines * 9 * t1;
				if ((reqd >= 0) and (reqd % (k + 1) == 0)) {
					int pref = genPref(reqd / (k + 1));
					ans = min(ans, pref * base + base - 10 + last);
				}
			}
		}
		if (ans == INF) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}