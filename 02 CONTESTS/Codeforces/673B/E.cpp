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

int dp[35][3];

void res(vector<int> &arr, int pos) {
	if (pos < 0) {
		return;
	}

	// for case bit is 0
	int count = 0;
	for (auto x : arr) {
		if (x & (1 << pos)) {
			count++;
		} else {
			dp[pos][0] += count;
		}
	}

	// for case bit is 1
	count = 0;
	for (auto x : arr) {
		if (x & (1 << pos)) {
			dp[pos][1] += count;
		} else {
			count++;
		}
	}

	vector<int> t1, t2;
	for (auto x : arr) {
		if (x & (1 << pos)) {
			t1.pb(x);
		} else {
			t2.pb(x);
		}
	}
	if (size(t1)) res(t1, pos - 1);
	if (size(t2)) res(t2, pos - 1);
}

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) cin >> a;
	res(arr, 30);
	int ans = 0, val = 0;
	for (int i = 30; i >= 0; i--) {
		if (dp[i][0] > dp[i][1]) {
			ans |= (1 << i);
			val += dp[i][1];
		} else {
			val += dp[i][0];
		}
	}
	cout << val << " " << ans << endl;
	return 0;
}