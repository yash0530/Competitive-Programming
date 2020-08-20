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

int32_t main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<pii> arr(m);
		for (int i = 0; i < m; i++) {
			cin >> arr[i].fs >> arr[i].sc;
		}
		sort(arr.begin(), arr.end(), greater<pii>());
		vector<int> firsts;
		for (auto a : arr) {
			firsts.pb(a.fs);
		}
		vector<int> pref(m + 1);
		for (int i = 0; i < m; i++) {
			pref[i + 1] = pref[i] + firsts[i];
		}
		int res = 0;
		if (n <= m) {
			res = pref[n];
		}
		for (auto a : arr) {
			int val = a.sc;
			int count = upper_bound(firsts.begin(), firsts.end(), val, greater<int>()) - firsts.begin();
			count = min(count, n);
			if (a.fs < val) {
				if ((n - count) > 0) {
					res = max(res, pref[count] + a.fs + (val * max(0LL, (n - count - 1))));
				}
			} else {
				res = max(res, pref[count] + (val * max(0LL, (n - count))));
			}
		}
		cout << res << endl;
	}
	return 0;
}