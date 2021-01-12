#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		for (auto &x : s) {
			x = !(x - '0') + '0';
		}
		vector<int> pref(n);
		for (int i = 0; i < n; i++) {
			pref[i] = s[i] - '0';
			if (i) pref[i] += pref[i - 1];
		}
		auto sum = [&](int a, int b) {
			if (a) return pref[b] - pref[a - 1];
			return pref[b];
		};
		set<int> vals;
		for (int i = k - 1; i < n; i++) {
			int val = 0, base = 1;
			for (int j = i; j >= max(i - (k - 1), i - 19); j--) {
				val += (s[j] - '0') * base;
				base *= 2;
			}
			if (k > 20) {
				if (sum(i - k + 1, i - 20) == 0) {
					vals.insert(val);
				}
			} else {
				vals.insert(val);
			}
		}
		int ans = 0;
		for (auto x : vals) {
			if (ans == x) {
				ans++;
			} else {
				break;
			}
		}
		string res = "";
		while (ans) {
			if (ans & 1) {
				res.pb('1');
			} else {
				res.pb('0');
			}
			ans /= 2;
		}
		if (size(res) > k) {
			cout << "NO" << endl;
		} else {
			for (int i = size(res); i < k; i++) {
				res.pb('0');
			}
			reverse(_all(res));
			cout << "YES" << endl << res << endl;
		}
	}
	return 0;
}