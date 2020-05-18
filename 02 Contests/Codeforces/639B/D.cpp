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

int n, m;
bool vis[1001][1001];
vector<string> mat;
vector<pii> d = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

void dfs(int i, int j) {
	vis[i][j] = true;
	for (auto x : d) {
		int ni = i + x.fs, nj = j + x.sc;
		if (ni >= 0 and ni < n) {
			if (nj >= 0 and nj < m) {
				if (!vis[ni][nj] and mat[ni][nj] == '#') {
					dfs(ni, nj);
				}
			}
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	bool souths[n][m], rows[n], cols[m];
	memset(souths, 0, sizeof souths);
	memset(rows, 0, sizeof rows);
	memset(cols, 0, sizeof cols);
	bool poss = true;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		mat.pb(s);
		int count = 0;
		char prev = '.';
		for (auto x : s) {
			if (prev == '.' and x == '#') {
				count++;
			}
			prev = x;
		}
		if (count > 1) {
			poss = false;
		}
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				rows[i] = 1;
				cols[j] = 1;
				souths[i][j] = 1;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int count = 0;
		char prev = '.';
		for (int i = 0; i < n; i++) {
			if (prev == '.' and mat[i][j] == '#') {
				count++;
			}
			prev = mat[i][j];
		}
		if (count > 1) {
			poss = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!rows[i] and !cols[j]) {
				souths[i][j] = 1;
			}
		}
	}
	memset(rows, 0, sizeof rows);
	memset(cols, 0, sizeof cols);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (souths[i][j]) {
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}
	if (n != accumulate(rows, rows + n, 0)) poss = false;
	if (m != accumulate(cols, cols + m, 0)) poss = false;
	if (poss) {
		int count = 0;
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] and mat[i][j] == '#') {
					dfs(i, j);
					count++;
				}
			}
		}
		cout << count << endl;
	} else {
		cout << -1 << endl;
	}
 	return 0;
}