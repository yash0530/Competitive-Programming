#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 1e16
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

int n;
const int maxN = 1e5 + 5;
int arr[maxN], dp[maxN][5];
string s;
vector<int> mp(128, -1);

int res(int ind, int till) {
	if (till == 4) {
		return INF;
	}
	if (ind == n) {
		return 0;
	}
	int &ans = dp[ind][till];
	if (ans == -1) {
		if (mp[s[ind]] == till) {
			ans = min(res(ind + 1, till + 1), res(ind + 1, till) + arr[ind]);
		} else {
			ans = res(ind + 1, till);
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mp['h'] = 0;
	mp['a'] = 1;
	mp['r'] = 2;
	mp['d'] = 3;
	memset(dp, -1, sizeof dp);
	cout << res(0, 0) << endl;
	return 0;
}
