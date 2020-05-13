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

int n, x1, x2, yy1, y2, x, y;
string s;

bool poss(int k) {
	int comp = k / n;
	int rem = k % n;
	int x3 = x * comp + x1, y3 = y * comp + yy1;
	for (int i = 0; i < rem; i++) {
		if (s[i] == 'U') {
			y3++;
		} else if (s[i] == 'L') {
			x3--;
		} else if (s[i] == 'R') {
			x3++;
		} else {
			y3--;
		}
	}
	return (abs(x3 - x2) + abs(y3 - y2)) <= k;
}

int32_t main() { fastio;
	cin >> x1 >> yy1 >> x2 >> y2 >> n >> s;
	for (auto a : s) {
		if (a == 'U') {
			y++;
		} else if (a == 'L') {
			x--;
		} else if (a == 'R') {
			x++;
		} else {
			y--;
		}
	}
	int ans = INF;
	int low = 0, high = 1e18;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (poss(mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
