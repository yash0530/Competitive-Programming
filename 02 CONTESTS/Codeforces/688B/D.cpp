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
	map<int, vector<int>> mp;
	mp[2] = { 1 }; int till = 2;
	for (int i = 4; i <= 1e18; i *= 2) {
		int now = till + i;
		mp[now] = mp[till];
		mp[now].pb(0);
		till = now;
	}
	vector<pair<int, vector<int>>> cache(_all(mp));
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n & 1) {
			cout << -1 << endl;
		} else {
			vector<int> res;
			for (int i = size(cache) - 1; i >= 0; i--) {
				while ((n - cache[i].fs) >= 0) {
					for (auto x : cache[i].sc) res.pb(x);
					n -= cache[i].fs;
				}
			}
			cout << size(res) << endl;
			for (auto x : res) {
				cout << x << " ";
			} cout << endl;
		}
	}
	return 0;
}