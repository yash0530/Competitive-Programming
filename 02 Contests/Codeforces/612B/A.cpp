#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int32_t main() { fastio;
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> p;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') {
				p.push_back(i);
			}
		}

		int sz = p.size();

		if (sz == 0) {
			cout << 0 << endl;
		} else {
			int res = n - 1 - p.back();
			for (int i = sz - 2; i >= 0; i--) {
				res = max(p[i + 1] - p[i] - 1, res);
			}
			cout << res << endl;
		}
	}
    return 0;
}
