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
		int n; cin >> n;
		map<string, int> counts;
		vector<string> aa(n), bb(n), cc(n);
		for (int i = 0; i < n; i++) {
			cin >> aa[i];
			counts[aa[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> bb[i];
			counts[bb[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> cc[i];
			counts[cc[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (counts[aa[i]] == 1) ans += 3;
			if (counts[aa[i]] == 2) ans += 1;
		}
		cout << ans << " ";
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (counts[bb[i]] == 1) ans += 3;
			if (counts[bb[i]] == 2) ans += 1;
		}
		cout << ans << " ";
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (counts[cc[i]] == 1) ans += 3;
			if (counts[cc[i]] == 2) ans += 1;
		}
		cout << ans << endl;
	}
	return 0;
}