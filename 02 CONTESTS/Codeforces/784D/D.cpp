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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		bool poss = true;
		int n; cin >> n;
		string temp; cin >> temp;
		string running = "";
		for (auto x : temp) {
			if (x == 'W') {
				if (size(running) == 1) {
					poss = false;
					break;
				}
				if (size(running)) {
					int r = 0, b = 0;
					for (auto y : running) {
						r += (y == 'R');
						b += (y == 'B');
					}
					if (!(r and b)) {
						poss = false;
						break;
					}
				}
				running = "";
			} else {
				running.push_back(x);
			}
		}
		if (size(running) == 1) {
			poss = false;
		}
		if (size(running)) {
			int r = 0, b = 0;
			for (auto y : running) {
				r += y == 'R';
				b += y == 'B';
			}
			if (!(r and b)) {
				poss = false;
			}
		}
		cout << (poss ? "YES" : "NO") << endl;
	}
	return 0;
}