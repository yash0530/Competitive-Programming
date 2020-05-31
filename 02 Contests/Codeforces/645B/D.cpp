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

int32_t main() { fastio;
	int n, x;
	cin >> n >> x;
	vector<int> arr(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	int mx = *max_element(arr.begin(), arr.end());
	if (mx >= x) {
		int ans = mx * (mx + 1) / 2;
		ans -= (mx - x) * (mx - x + 1) / 2;
		cout << ans << endl;
	} else {
		vector<int> c(2 * n), d(2 * n);
		c[0] = arr[0];
		d[0] = arr[0] * (arr[0] + 1) / 2;
		for (int i = 1; i < 2 * n; i++) {
			c[i] = c[i - 1] + arr[i];
			d[i] = d[i - 1] + (arr[i] * (arr[i] + 1) / 2);
		}
		int res = 0;
		for (int i = 1; i < 2 * n; i++) {
			int extra = c[i] - x;
			if (extra >= 0) {
				int loc = upper_bound(c.begin(), c.end(), extra) - c.begin();
				int ext = c[loc] - extra;
				int curr = (arr[loc] * (arr[loc] + 1) / 2);
				curr -= ((arr[loc] - ext) * (arr[loc] - ext + 1)) / 2;
				curr += d[i] - d[loc];
				res = max(res, curr);
			}
		}
		cout << res << endl;
	}
	return 0;
}
