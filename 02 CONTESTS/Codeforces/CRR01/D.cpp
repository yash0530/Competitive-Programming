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
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	vector<pii> res;
	set<pii> avails_one, avails_two;
	int col = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 1) {
			res.pb({ col, i + 1 });
			avails_one.insert({ col, i + 1 });
			col++;
		} else if (arr[i] == 2) {
			if (size(avails_one)) {
				auto avail = *avails_one.begin();
				avails_one.erase(avail);
				res.pb({ avail.fs, i + 1 });
				avails_two.insert(res.back());
			} else {
				cout << -1 << endl;
				exit(0);
			}
		} else if (arr[i] == 3) {
			if (size(avails_two)) {
				auto avail = *avails_two.begin();
				avails_two.erase(avail);
				res.pb({ col, i + 1 });
				avails_two.insert(res.back());	
				res.pb({ col, avail.sc });
				col++;
			} else if (size(avails_one)) {
				auto avail = *avails_one.begin();
				avails_one.erase(avail);
				res.pb({ col, i + 1 });
				avails_two.insert(res.back());	
				res.pb({ col, avail.sc });	
				col++;
			} else {
				cout << -1 << endl;
				exit(0);
			}
		}
	}
	cout << size(res) << endl;
	for (auto r : res) {
		cout << n - r.fs + 1 << " " << r.sc << endl;
	}
	return 0;
}