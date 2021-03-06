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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		set<int> ones;
		ones.insert(INT_MIN);
		ones.insert(INT_MAX);
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ones.insert(i);
		}
		int ans = 0;
		int last_one = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if ((i - last_one) > k) {
					auto x = ones.upper_bound(i);
					if (((*x) - i) > k) {
						s[i] = '1';
						last_one = i;
						ans++;
					}
				}
			} else {
				last_one = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}