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

int n, k;
const int maxN = 205;
string a, b;
int dp[maxN][maxN][maxN];

int res(int pos, int cntA, int rem, int cntB) {
	if (pos == n) {
		return 0;
	}
	int &ans = dp[pos][cntA][rem];
	if (ans == -1) {
		ans = 0;
		if (b[1] == b[0]) {
			if (a[pos] == b[0]) {
				ans = cntA + res(pos + 1, cntA + 1, rem, cntB);
			} else {
				ans = res(pos + 1, cntA, rem, cntB);
				if (rem) {
					ans = max(ans, cntA + res(pos + 1, cntA + 1, rem - 1, cntB));
				}
			}
		} else {
			if (a[pos] == b[0]) {
				ans = res(pos + 1, cntA + 1, rem, cntB);
				if (rem) {
					ans = max(ans, cntA + res(pos + 1, cntA, rem - 1, cntB + 1));
				}
			} else if (a[pos] == b[1]) {
				ans = cntA + res(pos + 1, cntA, rem, cntB + 1);
				if (rem) {
					ans = max(ans, res(pos + 1, cntA + 1, rem - 1, cntB));
				}
			} else {
				ans = res(pos + 1, cntA, rem, cntB);
				if (rem) {
					ans = max(ans, cntA + res(pos + 1, cntA, rem - 1, cntB + 1));
					ans = max(ans, res(pos + 1, cntA + 1, rem - 1, cntB));
				}
			}	
		}
	}
	return ans;
}

int32_t main() { fastio;
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	cin >> a >> b;
	cout << res(0, 0, k, 0) << endl;
	return 0;
}