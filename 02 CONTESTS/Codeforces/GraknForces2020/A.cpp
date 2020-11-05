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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x, y, z;
		vector<int> aa(n), bb(n), cc(n);
		for (auto &a : aa) cin >> a;
		for (auto &b : bb) cin >> b;
		for (auto &c : cc) cin >> c;
		cout << aa[0] << " ";
		int prev = aa[0];
		int ff = aa[0];
		for (int i = 1; i < n; i++) {
			x = aa[i], y = bb[i], z = cc[i];
			if (i == (n - 1)) {
				if (prev != x and ff != x) {
					cout << x << " ";
					prev = x;
				} else if (prev != y and ff != y) {
					cout << y << " ";
					prev = y;
				} else {
					cout << z << " ";
				}
			} else {
				if (prev != x) {
					cout << x << " ";
					prev = x;
				} else {
					cout << y << " ";
					prev = y;
				}
			}
		}
		cout << endl;
	}
	return 0;
}