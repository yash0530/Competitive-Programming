#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 2e12
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
const int maxN = 1e6 + 5;
vector<int> pos;
getMat(cache, maxN, 5, -1);

void preprocess() {
	for (int i = 0; i < size(pos); i++) {
		for (int j = 0; j < 5; j++) {
			cache[i][j] = -1;
		}
	}
	int move = n - pos.back();
	for (int i = 0; i < size(pos); i++) {
		pos[i] = (pos[i] + move) % n;
	}
	sort(pos.begin(), pos.end());
}

int dp(int loc, int prev) {
	if (loc == size(pos)) {
		if (prev == 1) {
			return INF;
		}
		return 0;
	}
	int &ans = cache[loc][prev];
	if (ans == -1) {
		if (prev == 0) {
			ans = dp(loc + 1, 1);
		}
		else if (prev == 1) {
			ans = dp(loc + 1, 2) + pos[loc] - pos[loc - 1];
		}
		else if (prev == 2) {
			ans = min(dp(loc, 0), dp(loc + 1, 3) + pos[loc] - pos[loc - 1]);
		}
		else {
			ans = dp(loc, 0);
		}
	}
	return ans;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		pos.clear();
		int x; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x) pos.pb(i);
		}
		if (size(pos) == 0) {
			cout << 0 << endl;
		} else if (size(pos) == 1) {
			cout << -1 << endl;
		} else {
			preprocess();
			int res = dp(0, 0);
			preprocess();
			res = min(res, dp(0, 0));
			preprocess();
			res = min(res, dp(0, 0));
			cout << res << endl;
		}
	}
	return 0;
}
