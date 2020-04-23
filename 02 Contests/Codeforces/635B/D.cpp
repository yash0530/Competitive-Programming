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

int f(int a, int b, int c) {
	return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vector<int> a1(n1), a2(n2), a3(n3);
		for (int i = 0; i < n1; i++) {
			cin >> a1[i];
		}
		for (int i = 0; i < n2; i++) {
			cin >> a2[i];
		}
		for (int i = 0; i < n3; i++) {
			cin >> a3[i];
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		sort(a3.begin(), a3.end());
		int res = INF;
		for (int i = 0; i < n1; i++) {
			int a = a1[i];
			auto x = upper_bound(a2.begin(), a2.end(), a);
			auto y = upper_bound(a3.begin(), a3.end(), a);
			vector<int> x_vals, y_vals;
			if (x != a2.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a2.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a2.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a3.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a3.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a3.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			x = lower_bound(a2.begin(), a2.end(), a);
			y = lower_bound(a3.begin(), a3.end(), a);
			if (x != a2.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a2.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a2.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a3.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a3.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a3.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			for (auto xv : x_vals) {
				for (auto yv : y_vals) {
					res = min(res, f(a, xv, yv));
				}
			}
		}
		for (int i = 0; i < n2; i++) {
			int a = a2[i];
			auto x = upper_bound(a1.begin(), a1.end(), a);
			auto y = upper_bound(a3.begin(), a3.end(), a);
			vector<int> x_vals, y_vals;
			if (x != a1.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a1.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a1.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a3.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a3.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a3.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			x = lower_bound(a1.begin(), a1.end(), a);
			y = lower_bound(a3.begin(), a3.end(), a);
			if (x != a1.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a1.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a1.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a3.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a3.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a3.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			for (auto xv : x_vals) {
				for (auto yv : y_vals) {
					res = min(res, f(a, xv, yv));
				}
			}
		}
		for (int i = 0; i < n3; i++) {
			int a = a3[i];
			auto x = upper_bound(a1.begin(), a1.end(), a);
			auto y = upper_bound(a2.begin(), a2.end(), a);
			vector<int> x_vals, y_vals;
			if (x != a1.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a1.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a1.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a2.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a2.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a2.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			x = lower_bound(a1.begin(), a1.end(), a);
			y = lower_bound(a2.begin(), a2.end(), a);
			if (x != a1.end()) {
				x_vals.pb(*x);
				x++;
				if (x != a1.end()) {
					x_vals.pb(*x);
				}
				x--;
			}
			if (x != a1.begin()) {
				x--;
				x_vals.pb(*x);
				x++;
			}

			if (y != a2.end()) {
				y_vals.pb(*y);
				y++;
				if (y != a2.end()) {
					y_vals.pb(*y);
				}
				y--;
			}
			if (y != a2.begin()) {
				y--;
				y_vals.pb(*y);
				y++;
			}

			for (auto xv : x_vals) {
				for (auto yv : y_vals) {
					res = min(res, f(a, xv, yv));
				}
			}
		}
		cout << res << en;
	}
	return 0;
}
