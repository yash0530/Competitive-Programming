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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	int mx = 0;
	vector<int> crr(n), drr(n);
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			crr[i] = crr[i - 1] + 1;
			mx = max(mx, crr[i]);
		}
	}
	for (int i = n - 2; i >= 0; i --) {
		if (arr[i] > arr[i + 1]) {
			drr[i] = drr[i + 1] + 1;
			mx = max(mx, drr[i]);
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (crr[i] == mx) count++;
		if (drr[i] == mx) count++;
	}
	if (count > 2) {
		cout << 0 << endl;
	} else {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (crr[i] == drr[i] and crr[i] == mx) {
				if (mx % 2 == 0) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}