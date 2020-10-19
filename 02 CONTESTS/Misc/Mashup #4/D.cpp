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

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	getMat(dp, n, n, 0);	
	for (int i = 0; i < n; i++) {
		int count_two = 0;
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = 1;
			} else {
				if (arr[j] == 1) {
					dp[i][j] = dp[i][j - 1] + 1;
				} else {
					dp[i][j] = max(dp[i][j - 1], count_two + 1);
				}
			}
			count_two += (arr[j] == 2);
		}
	}
	vector<int> one_pref(n + 2), two_pref(n + 2);
	for (int i = 1; i <= n; i++) {
		one_pref[i] = one_pref[i - 1] + (arr[i - 1] == 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		two_pref[i] = two_pref[i + 1] + (arr[i] == 2);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ans = max(ans, one_pref[i] + two_pref[j + 1] + dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}