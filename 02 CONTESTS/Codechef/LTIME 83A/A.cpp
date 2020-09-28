#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		map<int, int> H;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			H[arr[i]]++;
		}
		int last_elem = 0, ways = 1, res = 0;
		for (auto h : H) {
			int curr = fastpow(2, h.sc) - 1;
			if (ways and (last_elem + 1) == h.fs) {
				ways = (ways * ((fastpow(2, h.sc) - 1 + HELL) % HELL)) % HELL;
			} else {
				ways = 0;
			}
			res = (res + res * curr) % HELL;
			res = (res + curr) % HELL;
			res = (res + ways) % HELL;	
			last_elem = h.fs;
		}
		cout << res + 1 << endl;
	}
	return 0;
}
