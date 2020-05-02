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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		sort(s.begin(), s.end());
		map<char, int> x;
		for (auto y : s) x[y]++;

		// correct
		if (n == k) {
			cout << s.back() << endl;
		}
		// correct
		else if (k == 1) {
			cout << s << endl;
		}
		// correct
		else if (s[0] == s.back()) {
			cout << s.substr(0, (n + k - 1) / k) << endl;
		}
		else if (size(x) == 2) {
			// correct
			if (s[k - 1] != s[0]) {
				cout << s[k - 1] << endl;
			}
			else if (x[s[0]] == k) {
				cout << s[0];
				cout << s.substr(k, (x[s[k]] + k - 1) / k) << endl;
			}
			// incorrect
			else {
				for (int i = k - 1; i < n; i++) {
					cout << s[i];
				} cout << endl;
			}
		}
		else {
			// correct
			if (s[k - 1] != s[0]) {
				cout << s[k - 1] << endl;
			}
			else {
				for (int i = k - 1; i < n; i++) {
					cout << s[i];
				} cout << endl;
			}
		}
	}
	return 0;
}
