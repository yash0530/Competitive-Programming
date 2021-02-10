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
	vector<vector<int>> locs(n + 5);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		locs[arr[i]].pb(i);
	}
	for (auto &l : locs) {
		l.pb(INF);
		reverse(_all(l));
	}
	int count = 0;
	vector<int> r1, r2;
	for (auto x : arr) {
		locs[x].pop_back();
		if ((size(r1) and r1.back() != x) and (size(r2) and r2.back() != x)) {
			if (locs[r1.back()].back() < locs[r2.back()].back()) {
				r1.pb(x);
			} else {
				r2.pb(x);
			}
		} else if (r1.empty()) {
			r1.pb(x);
		} else if (r1.back() != x) {
			r1.pb(x);
		} else if (r2.empty()) {
			r2.pb(x);
		}  else if (r2.back() != x) {
			r2.pb(x);
		}
	}
	cout << size(r1) + size(r2) << endl;
	return 0;
}