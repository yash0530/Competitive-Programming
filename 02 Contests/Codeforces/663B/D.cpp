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

#define dist(a, b) __builtin_popcount(a ^ b)

int n, m;
const int maxN = 1e6 + 5, maxM = 8;
vector<int> mat;
int cache[maxN][maxM];

int tonum(string x) {
	int num = 0, base = 1;
	for (int i = size(x) - 1; i >= 0; i--) {
		num += base * (x[i] - '0');
		base *= 2;
	}
	return num;
}

bool poss(int a, int b) {
	if (m == 3) {
		return 
			(((a & 1) + (a & 2) / 2 + (b & 1) + (b & 2) / 2) & 1) and 
			(((a & 2) / 2 + (a & 4) / 4 + (b & 2) / 2 + (b & 4) / 4) & 1);
	}
	return (((a & 1) + (a & 2) / 2 + (b & 1) + (b & 2) / 2) & 1);
}

int dp(int pos, int mask) {
	if (pos == n) {
		return 0;
	}
	int &ans = cache[pos][mask];
	if (ans == -1) {
		ans = INF;
		for (int i = 0; i < (1 << m); i++) {
			if (poss(mask, i)) {
				ans = min(ans, dp(pos + 1, i) + dist(i, mat[pos]));
			}
		}
	}
	return ans;
}

int32_t main() {
	cin >> n >> m;
	memset(cache, -1, sizeof cache);
	if (n > 3 and m > 3) {
		cout << -1 << endl;
		exit(0);
	}
	if (n == 1 or m == 1) {
		cout << 0 << endl;
		exit(0);
	}
	vector<string> inp(n);
	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	if (n < m) {
		vector<vector<char>> temp(m, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[j][i] = inp[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			string x(temp[i].begin(), temp[i].end());
			mat.pb(tonum(x));
		}
		swap(n, m);
	} else {
		for (int i = 0; i < n; i++) {
			mat.pb(tonum(inp[i]));
		}
	}

	int res = INF;
	for (int i = 0; i < (1 << m); i++) {
		res = min(res, dp(1, i) + dist(i, mat[0]));
	}
	cout << res << endl;
	return 0;
}