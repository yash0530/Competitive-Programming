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
	int t; cin >> t;
	for (int _ = 1; _ <= t; _++) {
		cout << "Case #" << _ << ": ";

		int n; cin >> n;
		vector<pii> toys(n);

		for (int i = 0; i < n; i++) {
			cin >> toys[i].fs >> toys[i].sc;
		}
		if (n == 1) {
			cout << 0 << " " << toys[0].fs << endl;
			continue;
		}

		int res = 0, mn = INF;
		for (int mask = 1; mask <= (1LL << n); mask++) {
			vector<pii> curr;
			for (int i = 0; i < n; i++) {
				if ((1 << i) & (mask)) {
					curr.pb(toys[i]);
				}
			}
			if (size(curr)) {
 				int val = 0;
				if (size(curr) == 1) {
					val = curr[0].fs;
				} else {
					int sum = 0;
					bool in = true;
					for (auto c : curr) {
						sum += c.fs;
					}
					val = sum;
					for (auto c : curr) {
						if ((sum - c.fs) >= c.sc) {
							val += c.fs;
						} else {
							in = false;
							break;
						}
					}
					if (in) {
						val = INF;
					}
				}
				if (res < val) {
					mn = (n - size(curr));
					res = val;
				} else if (res == val) {
					mn = min(mn, (n - size(curr)));
				}
			}
		}
		cout << mn << " ";
		if (res == INF) {
			cout << "INDEFINITELY";
		} else {
			cout << res;
		}
		cout << endl;
	}
	return 0;
}