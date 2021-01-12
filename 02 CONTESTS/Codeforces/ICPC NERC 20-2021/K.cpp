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

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<pii> stops;
		int x = 0, y = 0;
		for (auto a : s) {
			if (a == 'L') {
				x--;
			} else if (a == 'R') {
				x++;
			} else if (a == 'U') {
				y++;
			} else {
				y--;
			}
			stops.pb({ x, y });
		}
		if (x == 0 and y == 0) {
			cout << 50000 << " " << 50000 << endl;
			continue;
		}
		bool poss = false;
		for (auto ss : stops) {
			int x = 0, y = 0;
			for (auto a : s) {
				if (a == 'L') {
					x--;
					if (ss.fs == x and ss.sc == y) {
						x++;
					}
				} else if (a == 'R') {
					x++;
					if (ss.fs == x and ss.sc == y) {
						x--;
					}
				} else if (a == 'U') {
					y++;
					if (ss.fs == x and ss.sc == y) {
						y--;
					}
				} else {
					y--;
					if (ss.fs == x and ss.sc == y) {
						y++;
					}
				}
			}
			if (x == 0 and y == 0) {
				cout << ss.fs << " " << ss.sc << endl;
				poss = true;
				break;
			}
		}
		if (!poss) {
			cout << 0 << " " << 0 << endl;
		}
	}
	return 0;
}