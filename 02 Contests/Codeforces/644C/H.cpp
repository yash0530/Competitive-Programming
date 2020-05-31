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

int val(string x) {
	int res = 0, base = 1;
	reverse(x.begin(), x.end());
	for (auto y : x) {
		res += (y - '0') * base;
		base <<= 1;
	}
	return res;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int m, n;
		cin >> n >> m;
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			string x; cin >> x;
			s[i] = val(x);
		}
		set<int> dels;
		int res = ((1LL << m) - 1) / 2, even = true;
		for (auto x : s) {
			dels.insert(x);
			if (even) {
				if (res == x) {
					while (dels.find(res) != dels.end()) {
						res++;
					}
				} else if (res > x) {
					res++;
					while (dels.find(res) != dels.end()) {
						res++;
					}
				}
			} else {
				if (res == x) {
					while (dels.find(res) != dels.end()) {
						res--;
					}
				} else if (res < x) {
					res--;
					while (dels.find(res) != dels.end()) {
						res--;
					}
				}
			}
			even = !even;
		}
		string ans = "";
		int i = 0;
		while (i < m) {
			ans.pb((res % 2) + '0');
			res >>= 1;
			i++;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}
