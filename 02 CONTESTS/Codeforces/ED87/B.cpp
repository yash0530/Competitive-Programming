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
		string s; cin >> s;
		int n = size(s);
		int len = 0, res = INF, low = 0, high = 0;
		vector<int> freq(4);
		while (low < n and high < n) {
			len++;
			freq[s[high] - '0']++;
			if (freq[1] and freq[2] and freq[3]) {
				res = min(res, len);
				deb(low);
				deb(high);
				while (low < n and freq[1] and freq[2] and freq[3]) {
					freq[s[low] - '0']--;
					low++;
					len--;
				}
				res = min(res, len + 1);
			}
			high++;
		}
		if (res == INF) cout << 0 << endl;
		else cout << res << endl;
	}
	return 0;
}
