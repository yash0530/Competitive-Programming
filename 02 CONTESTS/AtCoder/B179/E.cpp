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
#define inv(a, m) fastpow(a, m - 2)
#define mul(a, b, m) ((a % m) * (b % m)) % m

int32_t main() { fastio;
	int n, x, m;
	cin >> n >> x >> m;
	set<int> s;
	vector<int> okay;
	int curr = x, cycle_breaker = -1;
	while (true) {
		s.insert(curr);
		okay.pb(curr);
		curr = mul(curr, curr, m);
		if (s.find(curr) != s.end()) {
			cycle_breaker = curr;
			break;
		}
	}
	int res = 0;
	if (size(s) >= n) {
		for (int i = 0; i < n; i++) {
			res = res + okay[i];
		}
	} else if (okay.back() == 0) {
		for (auto y : okay) {
			res += y;
		}
	} else {
		int rem = 0;
		for (int i = 0; i < size(okay); i++) {
			if (okay[i] == cycle_breaker) {
				rem = i;
				break;
			}
			res += okay[i];
		}
		n -= rem;
		for (int i = rem, j = 0; j < (n % (size(s) - rem)); i++, j++) {
			res = res + okay[i];
		}
		for (int i = rem; i < size(okay); i++) {
			res += (okay[i] * (n / (size(s) - rem)));
		}
	}
	cout << res << endl;
	return 0;
}