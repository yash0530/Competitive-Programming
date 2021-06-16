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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> U(n), S(n);
		for (auto &u : U) cin >> u;
		for (auto &s : S) cin >> s;
		vector<int> okays[n + 1];
		vector<int> res(n + 1);
		for (int i = 0; i < n; i++) {
			okays[U[i]].pb(S[i]);
		}
		for (auto &o : okays) {
			sort(_all(o), greater<int>());
		}
		vector<int> will_add(n + 1);
		for (int i = 1; i <= n; i++) {
			int curr_n = size(okays[i]);
			vector<int> pref(curr_n + 1);
			for (int j = 0; j < curr_n; j++) {
				pref[j + 1] = pref[j] + okays[i][j];
			}
			for (int i = 1; i <= curr_n; i++) {
				int v = (curr_n / i) * i;
				will_add[i] += pref[v];
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << will_add[i] << " ";
		} cout << endl;
	}
	return 0;
}