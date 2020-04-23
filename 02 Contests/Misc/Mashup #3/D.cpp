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

int n, v, x, y;
const int maxN = 30005;
int fruits[maxN];
int mx;

int res(int ind = 0, int rem = 0) {
	if (ind == mx + 2) return 0;
	int atThis = rem + fruits[ind];
	if (atThis > v) {
		return res(ind + 1, min(fruits[ind], atThis - v)) + v;
	}
	return res(ind + 1, 0) + atThis;
}

int32_t main() { fastio;
	cin >> n >> v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		fruits[x] += y;
		mx = max(x, mx);
	}
	cout << res() << endl;
	return 0;
}
