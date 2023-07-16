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
		string a, s; cin >> a >> s;
		int i = size(a) - 1;
		int j = size(s) - 1;

		string x;
		while (j >= 0) {
			if (i < 0) {
				x.pb(s[j]); j--;
			} else {
				if (a[i] > s[j]) {
					if (j >= 1) {
						char aa = s[j] - a[i] + (s[j - 1] - '0') * 10 + '0';
						if ((aa - '0') >= 10 or (aa - '0') < 0) break;
						j -= 2; i--;
						x.pb(aa);
					} else break;
				} else {
					x.pb(s[j] - a[i] + '0');
					j--; i--;
				}
			}
			
		}
		if (i >= 0) {
			cout << -1 << endl;
			continue;
		}
		while (x.back() == '0') x.pop_back();
		reverse(x.begin(), x.end());
		cout << x << endl;
	}
	return 0;
}