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
		vector<int> arr(n);
		vector<pii> pairs(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			pairs[i] = { arr[i], i };
		}
		sort(_all(pairs));
		for (int i = 0; i < n; i++) {
			arr[pairs[i].sc] = i;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[i]) count++;
			}
		}
		if (count & 1) {
			for (int i = 0; i < (n - 1); i++) {
				if (pairs[i].fs == pairs[i + 1].fs) {
					swap(arr[pairs[i].sc], arr[pairs[i + 1].sc]);
					break;
				}
			}
		}

		auto rotate = [&](int loc) {
			swap(arr[loc], arr[loc - 2]);
			swap(arr[loc - 1], arr[loc]);
		};

		vector<int> res;
		for (int i = 0; i < n; i++) {
			int ml = min_element(arr.begin() + i, arr.end()) - arr.begin();
			while (ml > (i + 1)) {
				rotate(ml);
				res.pb(ml);
				ml -= 2;
			}
			if ((ml == (i + 1)) and (ml != (n - 1))) {
				res.pb(i + 2);
				res.pb(i + 2);
				rotate(i + 2);
				rotate(i + 2);
			}
		}
		if (arr[n - 3] <= arr[n - 2] and arr[n - 2] <= arr[n - 1]) {
		} else {
			rotate(n - 1);
			res.pb(n - 1);
		}
		if (arr[n - 3] <= arr[n - 2] and arr[n - 2] <= arr[n - 1]) {
		} else {
			rotate(n - 1);
			res.pb(n - 1);
		}
		if (arr[n - 3] <= arr[n - 2] and arr[n - 2] <= arr[n - 1]) {
			cout << size(res) << endl;
			for (auto r : res) {
				cout << r - 1 << " ";
			} cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}