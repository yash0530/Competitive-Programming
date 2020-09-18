// CSES Array Description
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

int n, m;
const int maxM = 105, maxN = 1e5 + 5;
int dp[maxN][maxM], arr[maxN];

int res(int pos, int prev) {
	if (pos == n) return 1;
	int &ans = dp[pos][prev];
	if (ans == -1) {
		ans = 0;
		if (arr[pos] == 0) {
			if (prev > 1)
				ans = res(pos + 1, prev - 1);
			ans = (ans + res(pos + 1, prev)) % HELL;
			if (prev < m)
				ans = (ans + res(pos + 1, min(m, prev + 1))) % HELL;
		} else {
			if (abs(prev - arr[pos]) <= 1) {
				ans = res(pos + 1, arr[pos]);
			}
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int count = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= m; i++) {
		if ((arr[0] == i) or (arr[0] == 0)) {
			count = (count + res(1, i)) % HELL;
		}
	}
	cout << count << endl;
	return 0;
}