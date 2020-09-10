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

int32_t main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	} else if (n < 4) {
		cout << "NO SOLUTION" << endl;
	} else {
		vector<int> base = { 2, 4, 1, 3 };
		int times = (n / 4);
		vector<int> res;
		for (int i = 0; i < times; i++) {
			int add = i * 4;
			for (auto b : base) {
				res.pb(b + add);
			}
		}
		if (n % 4 == 1) {
			res.pb(n);
		}
		if (n % 4 == 2) {
			cout << n - 1 << " ";
			res.pb(n);
		}
		if (n % 4 == 3) {
			cout << n - 1 << " ";
			res.pb(n - 2); res.pb(n);
		}
		for (auto r : res) {
			cout << r << " ";
		}
		cout << endl;
	}
	return 0;
}