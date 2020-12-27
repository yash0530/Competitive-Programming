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
	int n, a, b; cin >> n;
	vector<array<int, 2>> arr(n);
	vector<array<int, 2>> rr(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i][0] = a, arr[i][1] = b;
		if (i == 0) {
			rr[i][0] = a;
			rr[i][1] = a + b;
		} else {
			rr[i][0] = max(a, rr[i - 1][0] - 1);
			rr[i][1] = min(a + b, rr[i - 1][1] + 1);
		}

		if (rr[i][0] > rr[i][1]) {
			cout << -1 << endl;
			exit(0);
		}
	}
	vector<int> res(n);
	res[n - 1] = rr[n - 1][1];
	int ans = res[n - 1] - arr[n - 1][0];
	for (int i = n - 2; i >= 0; i--) {
		if ((res[i + 1] + 1) >= rr[i][0] and (res[i + 1] + 1) <= rr[i][1]) {
			res[i] = res[i + 1] + 1;
		} else if (res[i + 1] >= rr[i][0] and res[i + 1] <= rr[i][1]) {
			res[i] = res[i + 1];
		} else if ((res[i + 1] - 1) >= rr[i][0] and (res[i + 1] - 1) <= rr[i][1]) {
			res[i] = res[i + 1] - 1;
		}
		ans += res[i] - arr[i][0];
	}
	cout << ans << endl;
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
	return 0;
}