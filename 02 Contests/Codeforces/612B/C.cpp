#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int n;
int totalEvens, totalOdds;
const int maxN = 105;
int arr[maxN];
int dp[maxN][maxN][maxN][2];

int count(int a, int b) {
	if (b == -1) return 0;
	return (a & 1) != (b & 1);
}

int res(int index = 0, int evenUsed = 0, int oddUsed = 0, int last = -1) {
	if (index == n) {
		return 0;
	}
	if (last != -1) {
		if (dp[index][evenUsed][oddUsed][last] != -1) {
			return dp[index][evenUsed][oddUsed][last];
		}
	}
	if (arr[index]) {
		return res(index + 1, evenUsed, oddUsed, arr[index] & 1) + count(arr[index], last);		
	}
	int ans = INF;
	if (oddUsed < totalOdds) {
		ans = min(ans, res(index + 1, evenUsed, oddUsed + 1, 1) + count(1, last));
	}
	if (evenUsed < totalEvens) {
		ans = min(ans, res(index + 1, evenUsed + 1, oddUsed, 0) + count(0, last));
	}
	if (last != -1) {
		dp[index][evenUsed][oddUsed][last] = ans;
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> freq(n + 1);
	for (auto a : arr) {
		freq[a] = 1;
	}
	totalEvens = 0, totalOdds = 0;
	for (int i = 1; i <= n; i++) {
		if (!freq[i]) {
			totalEvens += !(i & 1);
			totalOdds += (i & 1);
		}
	}
	memset(dp, -1, sizeof dp);
	cout << res() << endl;
    return 0;
}
