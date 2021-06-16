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
		vector<int> freq(4);
		for (auto &f : freq) cin >> f;
		bool poss = false;
		for (int i = 0; i < 16; i++) {
			vector<int> vals;
			for (int x = 0; x < 4; x++) {
				if (i & (1LL << x)) {
					vals.pb(1);
				} else vals.pb(0);
			}

			// U
			int s = vals[0] + vals[1];
			int v = freq[0] - s;
			if ((v < 0) or (v > (n - 2))) continue;

			// R
			s = vals[1] + vals[2];
			v = freq[1] - s;
			if ((v < 0) or (v > (n - 2))) continue;

			// D
			s = vals[2] + vals[3];
			v = freq[2] - s;
			if ((v < 0) or (v > (n - 2))) continue;


			// L
			s = vals[3] + vals[0];
			v = freq[3] - s;
			if ((v < 0) or (v > (n - 2))) continue;
		
			poss = true;
			break;
		}
		cout << (poss ? "YES" : "NO") << endl;
	}
	return 0;
}