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

int n;
const int maxN = 2005;
pii arr[maxN];
int dp[maxN][maxN];

int res(int ind = 0, int left = 0, int right = n - 1) {
	if (ind == n or left < 0 or right >= n) {
		return 0;
	}
	int &ans = dp[left][right];
	if (ans == -1) {
		ans = abs(left - arr[ind].sc) * arr[ind].fs + res(ind + 1, left + 1, right);
		ans = max(ans, abs(right - arr[ind].sc) * arr[ind].fs + res(ind + 1, left, right - 1));
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].fs;
		arr[i].sc = i;
	}
	sort(arr, arr + n, greater<pii>());
	cout << res() << endl;
	return 0;
}
