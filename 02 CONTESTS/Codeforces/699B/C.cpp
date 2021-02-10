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
		int n, m; cin >> n >> m;
		vector<int> arr(n), brr(n), crr(m);
		for (auto &a : arr) cin >> a;
		for (auto &a : brr) cin >> a;
		for (auto &c : crr) cin >> c;

		vector<vector<int>> reqd(n + 5);
		vector<bool> inBrr(n + 5);
		set<int> changeEm;
		for (int i = 0; i < n; i++) {
			if (arr[i] != brr[i]) {
				reqd[brr[i]].pb(i);
				changeEm.insert(i);
			}
			inBrr[brr[i]] = true;
		}

		vector<int> wehaveCrr(n + 5);
		for (int i = 0; i < m; i++) {
			wehaveCrr[crr[i]]++;
		}

		vector<int> res(m);
		int loc = 0;
		for (int i = 0; i < m; i++) {
			int c = crr[i];
			if (size(reqd[c])) {
				res[i] = reqd[c].back();
				changeEm.erase(reqd[c].back());
				reqd[c].pop_back();
			} else {
				if (size(changeEm)) {
					res[i] = *changeEm.begin();
				} else {
					break;
				}
			}
			loc++;
		}
		if (size(changeEm)) {
			cout << "NO" << endl;
		} else {
			map<int, int> one_to_one;
			for (int i = 0; i < n; i++) {
				one_to_one[brr[i]] = i;
			}
			set<int> okays;
			for (int i = loc; i < m; i++) {
				if (inBrr[crr[i]]) {
					int loc = one_to_one[crr[i]];
					res[i] = loc;
					if (size(okays)) {
						for (auto o : okays) {
							res[o] = loc;
						}
						okays.clear();
					}
				} else {
					okays.insert(i);
				}
			}
			if (size(okays)) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
				for (auto &r : res) {
					cout << r + 1 << " ";
				} cout << endl;
			}
		}
	}
	return 0;
}