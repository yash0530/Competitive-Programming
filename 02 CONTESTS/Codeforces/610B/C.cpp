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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, T, a, b;
		cin >> n >> T >> a >> b;
		vector<pii> probs(n), counts(n + 1);
		for (int i = 0; i < n; i++) cin >> probs[i].sc;
		for (int i = 0; i < n; i++) cin >> probs[i].fs;
		sort(probs.begin(), probs.end());
		for (int i = n - 1; i >= 0; i--) {
			counts[i] = counts[i + 1];
			if (probs[i].sc) {
				counts[i].sc++;
			} else {
				counts[i].fs++;
			}
		}
		int ans = 0, cum = 0;
		int last = probs[0].fs - 1;
		int res = 0;
		int x = last / a;
		if (x) {
			res += min(x, counts[0].fs);
			last -= min(x, counts[0].fs) * a;
		}
		int y = last / b;
		if (y) {
			res += min(y, counts[0].sc);
		}
		ans = max(ans, res);
		for (int i = 0; i < n; ) {
			int curr = probs[i].fs;
			int till = i;
			while (till < n and probs[till].fs == curr) {
				if (probs[till].sc == 0) {
					cum += a;
				} else {
					cum += b;
				}
				till++;
			}
			i = till;
			if (till == n) {
				last = T;
			} else {
				last = probs[till].fs - 1;
			}
			if (cum <= last) {
				res = till;
				last = last - cum;
				x = last / a;
				if (x) {
					res += min(x, counts[i].fs);
					last -= min(x, counts[i].fs) * a;
				}
				y = last / b;
				if (y) {
					res += min(y, counts[i].sc);
				}
				ans = max(ans, res);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
