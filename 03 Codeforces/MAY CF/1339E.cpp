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
		int n; cin >> n;
		int x = (n + 2) / 3;
		int curr = 1;
		while (true) {
			if (x <= curr) {
				break;
			}
			x -= curr;
			curr <<= 2;
		}
		int val = curr + x - 1;
		if (n % 3 == 1) {
			cout << val << endl;
		} else if (n % 3 == 2) {
			int ans = 0;
			for (int i = 0; i < 60; i += 2) {
				int a = (1LL << i) & val, b = (1LL << (i + 1)) & val;
				if (a and b) {
					ans += (1LL << i);
				} else if (a) {
					ans += (1LL << (i + 1));
				} else if (b) {
					ans += (1LL << (i));
					ans += (1LL << (i + 1));
				}
			}
			cout << ans << endl;
		} else {
			int ans = 0;
			for (int i = 0; i < 60; i += 2) {
				int a = (1LL << i) & val, b = (1LL << (i + 1)) & val;
				if (a and b) {
					ans += (1LL << (i + 1));
				} else if (a) {
					ans += (1LL << (i + 1));
					ans += (1LL << (i));
				} else if (b) {
					ans += (1LL << (i));
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
