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

int n, m, q;
int ans;
vector<int> Q[51];
vector<int> curr;

void genPerms() {
	if (size(curr) == n) {
		int val = 0;
		for (int i = 1; i <= q; i++) {
			if (curr[Q[i][1] - 1] - curr[Q[i][0] - 1] == Q[i][2]) {
				val += Q[i][3];
			}
		}
		ans = max(val, ans);
		return;
	}
	int start = 1;
	if (size(curr)) start = curr.back();
	for (int i = start; i <= m; i++) {
		curr.pb(i);
		genPerms();
		curr.pop_back();
	}
}

int32_t main() { fastio;
	cin >> n >> m >> q;
	int a, b, c, d;
	for (int i = 1; i <= q; i++) {
		cin >> a >> b >> c >> d;
		Q[i] = { a, b, c, d };
	}
	genPerms();
	cout << ans << endl;
	return 0;
}
