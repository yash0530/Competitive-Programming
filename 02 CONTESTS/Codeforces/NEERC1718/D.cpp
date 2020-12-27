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
	int n; cin >> n;
	string s; cin >> s;
	vector<bool> avails(128);
	bool found = false;
	for (auto x : s) {
		avails[x] = true;
		if (x == '*') found = true;
	}
	if (!found) {
		cout << 0 << endl;
		exit(0);
	}
	vector<int> freq(128);
	int count = 0;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		vector<int> curr(128);
		string y; cin >> y;
		bool dead = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '*' and avails[y[i]]) {
				dead = true;
				break;
			}
			if (s[i] != '*' and s[i] != y[i]) {
				dead = true;
				break;
			}
		}
		if (!dead) {
			count++;
			for (int i = 0; i < n; i++) {
				if (s[i] == '*') {
					curr[y[i]] = 1;
				}
			}
			for (int i = 0; i < 128; i++) {
				freq[i] += curr[i];
			}
		}
	}
	int ans = 0;
	for (auto f : freq) {
		if (f == count) ans++;
	}
	cout << ans << endl;
	return 0;
}