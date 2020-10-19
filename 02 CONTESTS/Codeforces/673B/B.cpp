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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		set<int> FREQ;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			FREQ.insert(arr[i]);
		}
		map<int, int> ans;
		for (auto m : FREQ) {
			if (FREQ.find(k - m) != FREQ.end()) {
				ans[m] = 1;
				ans[k - m] = 0;
			} else {
				ans[m] = 1;
			}
		}
		vector<int> res(n, -1);
		if (k % 2 == 0) {
			int val = k / 2;
			bool curr = false;
			for (int i = 0; i < n; i++) {
				if (arr[i] == val) {
					res[i] = curr;
					curr = !curr;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (res[i] == -1) {
				cout << ans[arr[i]] << " ";
			} else {
				cout << res[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}