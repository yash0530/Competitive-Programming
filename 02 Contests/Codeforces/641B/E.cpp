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
	int n, m, t;
	cin >> n >> m >> t;
	vector<string> s(n);
	bool all_bad = true;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	getMat(vis, n, m, 0);
	getMat(dist, n, m, 0);
	queue<pair<pii, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool found = false;
			if (i and s[i - 1][j] == s[i][j]) {
				found = true;
			}
			if (j and s[i][j - 1] == s[i][j]) {
				found = true;
			}
			if (i < n - 1 and s[i + 1][j] == s[i][j]) {
				found = true;
			}
			if (j < m - 1 and s[i][j + 1] == s[i][j]) {
				found = true;
			}
			vis[i][j] = found;
			if (found) {
				Q.push({ { i, j }, 0 });
				all_bad = false;
			}
		}
	}
	while (!Q.empty()) {
		pii loc = Q.front().fs;
		int dis = Q.front().sc; Q.pop();
		if (loc.fs and !vis[loc.fs - 1][loc.sc]) {
			vis[loc.fs - 1][loc.sc] = true;
			dist[loc.fs - 1][loc.sc] = dis + 1;
			Q.push({ { loc.fs - 1, loc.sc }, dis + 1 });
		}
		if (loc.sc and !vis[loc.fs][loc.sc - 1]) {
			vis[loc.fs][loc.sc - 1] = true;
			dist[loc.fs][loc.sc - 1] = dis + 1;
			Q.push({ { loc.fs, loc.sc - 1 }, dis + 1 });
		}
		if (loc.fs < n - 1 and !vis[loc.fs + 1][loc.sc]) {
			vis[loc.fs + 1][loc.sc] = true;
			dist[loc.fs + 1][loc.sc] = dis + 1;
			Q.push({ { loc.fs + 1, loc.sc }, dis + 1 });
		}
		if (loc.sc < m - 1 and !vis[loc.fs][loc.sc + 1]) {
			vis[loc.fs][loc.sc + 1] = true;
			dist[loc.fs][loc.sc + 1] = dis + 1;
			Q.push({ { loc.fs, loc.sc + 1 }, dis + 1 });
		}
	}
	int i, j, k;
	while (t--) {
		cin >> i >> j >> k;
		i--; j--;
		if (all_bad or dist[i][j] > k) {
			cout << s[i][j] << endl;
		} else {
			k -= dist[i][j];
			if (k % 2 == 0) {
				cout << s[i][j] << endl;
			} else {
				cout << 1 - (s[i][j] - '0') << endl;
			}
		}
	}
	return 0;
}
