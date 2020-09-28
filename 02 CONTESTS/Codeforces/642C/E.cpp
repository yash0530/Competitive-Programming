#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		int total = 0;
		vector<int> prefix(n);
		for (int i = 0; i < n; i++) {
			total += s[i] - '0';
			prefix[i] = total;
		}
		int count = 0;
		getMat(dp, n, 2, INF);
		for (int i = 0; i < k; i++) {
			dp[i][0] = count;
			dp[i][1] = count;
			if (s[i] == '1') {
				count++;
				dp[i][0]++;
			} else {
				dp[i][1]++;
			}
		}
		for (int i = k; i < n; i++) {
			int mid = count;
			if (i) {
				mid -= prefix[i - k];
				dp[i][0] = dp[i - k][0] + mid + (s[i] == '1');
				dp[i][0] = min(dp[i][0], dp[i - k][1] + mid + (s[i] == '1'));
				dp[i][1] = dp[i - k][1] + mid + (s[i] == '0');
				dp[i][1] = min(dp[i][1], count + (s[i] == '0'));
			} else {
				dp[i][0] = (s[i] == '1');
				dp[i][1] = (s[i] == '0');
			}
			if (s[i] == '1') count++;
		}
		int ans = total;
		for (int i = n - 1, j = 0; j < k; j++, i--) {
			ans = min(ans, min(dp[i][0] + total - prefix[i], dp[i][1] + total - prefix[i]));
		}
		cout << ans << endl;
	}
	return 0;
}