#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e12
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << "\t"; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)
#define size(a) (int) a.size()

int32_t main() { fastio;
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<vector<int>> last(n, vector<int>(26, -1));
	last[0][s[0] - 'a'] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			last[i][j] = last[i - 1][j];
		}
		last[i][s[i] - 'a'] = i;
	}

	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	} dp[0][1] = 1;

	for (int idx = 1; idx < n; idx++) {
		for (int len = 1; len <= (idx + 1); len++) {

			dp[idx][len] = dp[idx - 1][len];
			int val = dp[idx - 1][len - 1];

			if (last[idx - 1][s[idx] - 'a'] != -1) {
				if (last[idx - 1][s[idx] - 'a'] > 0) {
					val -= dp[last[idx - 1][s[idx] - 'a'] - 1][len - 1];
				} else if (len == 1) {
					val--;
				}
			}

			dp[idx][len] = min(INF, dp[idx][len] + val);
		}
	}

	int res = 0;
	for (int j = n; j > 0; j--) {
		if (k > dp[n - 1][j]) {
			k -= dp[n - 1][j];
			res += dp[n - 1][j] * (n - j);
		} else {
			res += k * (n - j);
			cout << res << endl;
			exit(0);
		}
	}
	if (k == 1) {
		cout << res + n << endl;
	} else {
		cout << -1 << endl;
	}

    return 0;
}
