#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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

int n, m;
const int maxN = 3007;
string s, t;
int dp[maxN][maxN];

int res(int left, int right, int ind) {
	int &ans = dp[left + 2][right + 2];
	if (ans == -1) {
		ans = 0;
		if (left == -1 and right == n) {
			ans = 1;
		}
		else if (left == right) {
			if (left >= m or t[left] == s[ind]) {
				ans = res(left - 1, right + 1, ind + 1);
			}
		}
		else if (left == -1) {
			if (right >= m) {
				ans = 1 + res(left, right + 1, ind + 1);
			} else if (t[right] == s[ind]) {
				ans = res(left, right + 1, ind + 1);
			}
		}
		else if (right == n) {
			if (left >= m or t[left] == s[ind]) {
				ans = res(left - 1, right, ind + 1);
			}
		}
		else {
			if (left >= m or t[left] == s[ind]) {
				ans += res(left - 1, right, ind + 1);
			}
			if (right >= m or t[right] == s[ind]) {
				ans += res(left, right + 1, ind + 1);
			}
		}
		ans = ans % HELL;
	}
	return ans;
}

int32_t main() { fastio;
	cin >> s >> t;
	memset(dp , -1, sizeof dp);
	n = size(s); m = size(t);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + res(i, i, 0)) % HELL;
	}
	cout << (2 * ans) % HELL << endl;
	return 0;
}
