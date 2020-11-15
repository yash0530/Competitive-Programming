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

bool check(vector<int> &arr, int val) {
	for (auto x : arr) {
		if ((__gcd(x, val) == 1) or (x % val == 0) or (val % x) == 0) {
			return false;
		}
	}
	return true;
}

signed main() { fastio;
	vector<int> final_ans[101];
	for (int n = 1; n <= 100; n++) {
		for (int chk = 1; chk <= 400; chk++) {
			vector<int> ans;
			for (int i = chk; i <= 400; i++) {
				if (!size(ans) or check(ans, i)) {
					ans.pb(i);
				}
			}
			if (size(ans) >= n and ans[n - 1] <= (4 * n)) {
				final_ans[n] = vector<int>(ans.begin(), ans.begin() + n);
				break;
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (auto x : final_ans[n]) {
			cout << x << " ";
		} cout << endl;
	}
	return 0;
}