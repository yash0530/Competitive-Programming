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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

array<int, 3> solve(vector<int> arr, int n) {
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) pos.pb(i);
	}
	if (!(size(pos) & 1)) {
		int prod = 0;
		for (int i = 0; i < n; i++) {
			prod += abs(arr[i]) == 2;
		}
		return { 0, 0, prod };
	} else {
		int prodA = 0, prodB = 0;
		for (int i = pos[0] + 1; i < n; i++) {
			prodA += abs(arr[i]) == 2;
		}
		for (int i = pos.back() - 1; i >= 0; i--) {
			prodB += abs(arr[i]) == 2;
		}
		int left = pos[0] + 1;
		int right = n - pos.back();
		if (prodA >= prodB) {
			return { left , 0, prodA };
		} else {
			return { 0, right, prodB };
		}
	}
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		vector<int> zs;
		zs.pb(-1);
		array<int, 3> res = { 0, n, 0 };
		for (int i = 0; i <= n; i++) {
			if (i == n or arr[i] == 0) {
				zs.pb(i);
				vector<int> temp;
				for (int i = zs[size(zs) - 2] + 1; i < zs.back(); i++) {
					temp.pb(arr[i]);
				}
				array<int, 3> mid = solve(temp, size(temp));
				if (mid[2] > res[2]) {
					res = { zs[size(zs) - 2] + 1 + mid[0], n - zs.back() + mid[1], mid[2] };
				}
			}
		}
		cout << res[0] << " " << res[1] << endl;
	}
	return 0;
}