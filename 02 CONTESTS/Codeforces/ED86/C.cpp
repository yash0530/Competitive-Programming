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

int small, large;

int getVal(int num) {
	num++;
	int curr = num / (small + large);
	curr *= large;
	num = num % (small + large);
	num -= small;
	curr += max(num, 0LL);
	return curr;
}

int32_t main() { fastio;

	int t; cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;
		small = max(a, b); large = ((a * b) / __gcd(a, b)) - small;
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << getVal(r) - getVal(l - 1) << " ";
		} cout << endl;
	}
	return 0;
}
