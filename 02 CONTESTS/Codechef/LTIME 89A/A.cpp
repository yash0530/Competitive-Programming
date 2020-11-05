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

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		vector<int> okays;
		okays.pb(arr[0]);
		for (int i = 1; i < n; i++) {
			if (okays.back() != arr[i]) {
				okays.pb(arr[i]);
			}
		}
		int ans = size(okays);
		while (q--) {
			int p, v;
			cin >> p >> v;
			p--;
			if (n == 1) {}
			else if (p == 0) {
				if (v != arr[p + 1] and arr[p] == arr[p + 1]) ans++;
				if (v == arr[p + 1] and arr[p] != arr[p + 1]) ans--;
			} else if (p == (n - 1)) {
				if (v != arr[p - 1] and arr[p] == arr[p - 1]) ans++;
				if (v == arr[p - 1] and arr[p] != arr[p - 1]) ans--;
			} else {
				if (v != arr[p + 1] and arr[p] == arr[p + 1]) ans++;
				if (v == arr[p + 1] and arr[p] != arr[p + 1]) ans--;
				if (v != arr[p - 1] and arr[p] == arr[p - 1]) ans++;
				if (v == arr[p - 1] and arr[p] != arr[p - 1]) ans--;
			}
			arr[p] = v;
			cout << ans << endl;
		}
	}
	return 0;
}