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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		getMat(mat, n, m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < ((n + 1) / 2); i++) {
			for (int j = 0; j < ((m + 1) / 2); j++) {
				vector<int> elems;
				elems.pb(mat[i][j]);
				if (i != (n - i - 1) and j != (m - j - 1))
					elems.pb(mat[n - i - 1][m - j - 1]);
				if (i != (n - i - 1))
					elems.pb(mat[n - i - 1][j]);
				if (j != (m - j - 1)) {
					elems.pb(mat[i][m - j - 1]);
				}
				int curr = INF;
				
				for (auto x : elems) {
					int now = 0;
					for (auto y : elems) {
						now += abs(x - y);
					}
					curr = min(curr, now);
				}

				int sum = 0;
				for (auto x : elems) sum += x;
				vector<int> nw;
				nw.pb(sum / size(elems));
				nw.pb(nw.back() + 1);
				nw.pb(nw[0] - 1);
				for (auto x : nw) {
					int now = 0;
					for (auto y : elems) {
						now += abs(x - y);
					}
					curr = min(curr, now);
				}
				ans += curr;
			}
		}
		cout << ans << endl;
	}
	return 0;
}