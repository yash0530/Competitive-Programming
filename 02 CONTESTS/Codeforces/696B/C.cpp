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
		int n; cin >> n;
		int N = 2 * n;
		vector<int> arr(N);
		for (auto &a : arr) cin >> a;
		sort(_all(arr));
		bool poss = false;
		vector<array<int, 2>> res;
		int final_x;
		for (int o = 0; o < (N - 1); o++) {
			int x = arr.back() + arr[o];
			multiset<int> ss;
			int now = arr.back();
			vector<array<int, 2>> curr_res;
			curr_res.pb({ arr.back(), arr[o] });
			for (int i = 0; i < (N - 1); i++) {
				if (i != o) ss.insert(arr[i]);
			}
			for (int i = 0; i < (n - 1); i++) {
				int a = *ss.rbegin();
				ss.erase(ss.find(a));
				if (ss.find(now - a) == ss.end()) break;
				int b = *ss.find(now - a);
				ss.erase(ss.find(b));
				curr_res.pb({ a, b });
				now = a;
			}

			if (ss.empty()) {
				poss = true;
				final_x = x;
				res = curr_res;
			}
		}
		if (poss) {
			cout << "YES" << endl;
			cout << final_x << endl;
			for (auto x : res) {
				for (auto y : x) {
					cout << y << " ";
				} cout << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}