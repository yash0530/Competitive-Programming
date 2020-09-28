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
	int n, k; string s;
	cin >> n >> k >> s;
	stack<int> pos;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') pos.push(i);
	}
	vector<int> left(n, -1);
	if (size(pos)) {
		int loc = n - 1;
		while (loc >= 0) {
			int curr = pos.top();
			while (size(pos) and pos.top() + k >= loc) {
				curr = pos.top();
				pos.pop();
			}
			pos.push(curr);
			if ((curr - k) <= loc and (curr + k) >= loc) {
				left[loc] = curr;
			}
			loc--;
		}
	}
	vector<int> dp(n + 1, INF); dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = min(dp[i], dp[i + 1] + i + 1);
		if (left[i] != -1) {
			int low = max(0LL, left[i] - k);
			dp[low] = min(dp[low], dp[i + 1] + left[i] + 1);
		}
	}
	cout << dp[0] << endl;
	return 0;
}
