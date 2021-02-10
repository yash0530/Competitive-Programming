#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

signed main() { fastio;
	vector<set<int>> digs(10);
	for (int i = 1; i <= 2000; i++) {
		int num = i;
		while (num) {
			int dig = (num % 10);
			if (dig) {
				digs[dig].insert(i);
			}
			num /= 10;
		}
	}
	getMat(poss, 10, 2005, 0);
	for (int i = 1; i < 10; i++) {
		poss[i][0] = 1;
		for (int loc = 1; loc <= 2000; loc++) {
			for (auto x : digs[i]) {
				if ((loc - x) >= 0) {
					poss[i][loc] = poss[i][loc - x] or poss[i][loc - x];
					if (poss[i][loc]) break;
				}
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int q, d;
		cin >> q >> d;
		while (q--) {
			int n; cin >> n;
			if (n > 2000) {
				cout << "YES" << endl;
			} else {
				if (poss[d][n]) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
		}
	}
	return 0;
}