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

void solve() {
	int a, b, c; cin >> a >> b >> c;
	bool done = false;
	for (int X = 0; X <= 43200; X++) {
		int x = ((int)(a * 120 / (12 * 1e10)) + X) % 43200;
		int y = ((int)(b * 120 / (12 * 1e10)) + X) % 43200;
		int z = ((int)(c * 120 / (12 * 1e10)) + X) % 43200;
		vector<int> arr = { x, y, z };
		vector<int> prem = { 1, 2, 3 };
		bool done = false;
		do {
			vector<int> ans = { arr[prem[0] - 1] / 3600, arr[prem[1] - 1] / 720, arr[prem[2] - 1] / 720 };
			int S = ans[2] * 720;
			int M = ans[1] * 720 + 12 * ans[2];
			int H = ans[0] * 3600 + ans[1] * 60 + ans[2];
			vector<int> xx = { S, M, H };
			vector<int> temp = arr;
			sort(_all(temp));
			sort(_all(xx));
			if (xx == temp) {
				for (auto a : ans) {
					cout << a << " ";
				} cout << 0 << endl;
				done = true;
				break;			
			}
		} while (next_permutation(_all(prem)));	
		if (done) break;
	}
}

signed main() { fastio;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}