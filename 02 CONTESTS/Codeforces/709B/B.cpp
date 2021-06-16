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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) cin >> a;
		if (n <= 2) {
			cout << 0 << endl;
			continue;
		}
		bool cons = false;
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1]) cons = true;
		}

		vector<int> temp = arr;
		sort(_all(temp));
		if ((!cons or (temp[0] == temp.back())) and temp == arr) {
			cout << 0 << endl;
			continue;
		}

		if (cons) {
			cout << -1 << endl;
			continue;
		}

		set<int> ds;
		for (int i = 1; i < n; i++) {
			if ((arr[i] - arr[i - 1]) >= 0) {
				ds.insert(arr[i] - arr[i - 1]);
			}
		}

		if (size(ds) != 1) {
			cout << -1 << endl;
			continue;
		}

		int dd = *ds.begin();
		set<int> ms;
		for (int i = 0; i < (n - 1); i++) {
			if ((arr[i] > arr[i + 1])) {
				ms.insert(arr[i] + dd - arr[i + 1]);
			}
		}

		if (size(ms) == 0) {
			cout << 0 << endl;
		} else if (size(ms) == 1) {
			int mm = *ms.begin();
			vector<int> curr = { arr[0] };
			for (int i = 1; i < n; i++) {
				curr.pb((dd + curr.back()) % mm);
			}
			bool poss = true;
			for (auto x : curr) {
				if (x >= mm) poss = false;
			}
			if (poss and (curr == arr)) {
				cout << mm << " " << dd << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}