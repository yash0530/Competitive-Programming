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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = size(s);
		vector<int> zerosp(n), onesp(n), zeross(n), oness(n);
		for (int i = 0; i < n; i++) {
			if (i) zerosp[i] += zerosp[i - 1];
			if (i) onesp[i] += onesp[i - 1];
			if (s[i] == '0') {
				zerosp[i]++;
			}
			if (s[i] == '1') {
				onesp[i]++;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i != n - 1) zeross[i] += zeross[i + 1];
			if (i != n - 1) oness[i] += oness[i + 1];
			if (s[i] == '0') {
				zeross[i]++;
			}
			if (s[i] == '1') {
				oness[i]++;
			}
		}
		int res = min(onesp.back(), zerosp.back());
		for (int i = 0; i < n - 1; i++) {
			int curr0 = 0, curr1 = 0;
			curr0 += onesp[i];
			curr1 += zerosp[i];
			curr0 += zeross[i + 1];
			curr1 += oness[i + 1];
			res = min(res, min(curr0, curr1));
		}
		cout << res << endl;
	}
	return 0;
}
