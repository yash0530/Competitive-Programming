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
		int a, b;
		cin >> a >> b;
		string s; cin >> s;
		int ans = 0;
		vector<pii> pos;
		int prev = 'X';
		for (auto x : s) {
			if (x == prev) {
				pos[size(pos) - 1].fs++;
			} else {
				if (x == '1') ans += a;
				pos.pb({ 1, x });
			}
			prev = x;
		}
		for (int i = 0; i < size(pos); i++) {
			auto p = pos[i];
			if (p.sc == '0' and (i and (i != (size(pos) - 1)))) {
				if (b * p.fs < a) {
					ans -= a;
					ans += (b * p.fs);
				}
			}
		}
		cout << ans << endl;

	}
	return 0;
}