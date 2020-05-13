#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

int dp[5000][5000];
int n, arr[5000];

int res(int left, int right) {
	if (left == 0 and right == n - 1) {
		return 0;
	}
	int &ans = dp[left][right];
	if (ans == -1) {
		ans = 1e9;
		if (right < n - 1) {
			ans = min(ans, res(left, right + 1) + (arr[right] != arr[right + 1]));
		}
		if (left > 0) {
			ans = min(ans, res(left - 1, right) + (arr[left] != arr[left - 1]));
		}
		if (left > 0 and right < n - 1 and arr[left - 1] == arr[right + 1]) {
			ans = min(ans, res(left - 1, right + 1) + 1);
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		ans = min(ans, res(i, i));
	}
	cout << ans << endl;
	return 0;
}
