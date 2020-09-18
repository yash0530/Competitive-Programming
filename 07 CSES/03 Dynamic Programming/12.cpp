// CSES Removal Game
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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n;
const int maxN = 5005;
int dp[maxN][maxN][2], arr[maxN];

int res(int left, int right, int player) {
	if (left == right) {
		if (player)
			return arr[left];
		else return 0;
	}
	if (left > right) return 0;
	int &ans = dp[left][right][player];
	if (ans == -1) {
		if (player) {
			ans = max(arr[left] + res(left + 1, right, 0), arr[right] + res(left, right - 1, 0));
		} else {
			ans = min(res(left + 1, right, 1), res(left, right - 1, 1));
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
	cout << res(0, n - 1, 1) << endl;
	return 0;
}