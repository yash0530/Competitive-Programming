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
	vector<int> arr(n);
	int xr = 0;
	for (auto &a : arr) {
		cin >> a;
		xr = a ^ xr;
	}
	bool poss = true;
	if (n % 2 == 0 and xr) {
		poss = false;
	}
	if (n % 2 == 0 and !xr) {
		n--;
	}
	if (poss) {
		cout << "YES" << endl;
		vector<array<int, 3>> ans;
		for (int i = 0; i < (n - 2); i += 2) {
			ans.pb({ i + 1, i + 2, i + 3 });
		}
		for (int i = 0; i < (n - 1); i += 2) {
			ans.pb({ i + 1, i + 2, n });
		}
		cout << size(ans) << endl;
		for (auto a : ans) {
			for (auto x : a) cout << x << " ";
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}