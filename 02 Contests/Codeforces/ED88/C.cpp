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
	int tc; cin >> tc;
	while (tc--) {
		int h, c, t;
		cin >> h >> c >> t;
		if (t == h) {
			cout << 1 << endl;
		} else {
			int res = 1;
			int low = 1, high = 1e12;
			while (low < high) {
				int mid = (low + high) / 2;
				double in = (double) (h * mid + c * (mid - 1)) / (double)(2 * mid - 1);
				if (in == t) {
					res = mid;
					break;
				}
				if (in > t) {
					res = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			double in = (double) (h * res + c * (res - 1)) / (double)(2 * res - 1);
			double s2 = (double) (h + c) / (double) 2;
			if (abs(in - t) >= abs(t - s2)) {
				double in2 = (double) (h * (res + 1) + c * (res)) / (double)(2 * res + 1);
				if (abs(in2 - t) >= abs(t - s2)) {
					cout << 2 << endl;
				} else
					cout << res * 2 + 1 << endl;
			} else {
				double in2 = (double) (h * (res + 1) + c * (res)) / (double)(2 * res + 1);
				if (abs(in - t) > abs(t - in2)) {
					cout << res * 2 + 1 << endl;
				} else
					cout << res * 2 - 1 << endl;
			}
		}
	}
	return 0;
}