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
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a % b) {
			cout << -1 << endl;
		} else {
			int r = a / b;
			if (r == 1) cout << 0 << endl;
			else if (r % 2) {
				cout << -1 << endl;
			} else {
				int ans = 0;
				bool done = true;
				while (r % 8 == 0) {
					ans++;
					r /= 8;
					if (r != 1 and r & 1) {
						done = false;
					}
				}
				while (r % 4 == 0) {
					ans++;
					r /= 4;
					if (r != 1 and r & 1) {
						done = false;
					}
				}
				while (r % 2 == 0) {
					ans++;
					r /= 2;
					if (r != 1 and r & 1) {
						done = false;
					}
				}
				if (done)
					cout << ans << endl;
				else cout << -1 << endl;
			}
		}
	}
	return 0;
}
