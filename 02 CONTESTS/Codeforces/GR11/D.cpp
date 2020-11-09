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
	int n; cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		exit(0);
	}
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	auto update = [&](vector<int> &change) {
		vector<vector<int>> okays;
		int loc = 0;
		for (auto c : change) {
			okays.pb(vector<int>(arr.begin() + loc, arr.begin() + loc + c));
			loc += c;
		}
		reverse(_all(okays));
		vector<int> temp;
		for (auto x : okays) {
			for (auto y : x) {
				temp.pb(y);
			}
		}
		arr = temp;
	};

	auto change = [&](int left, int right) {
		int z = -1;
		for (int i = left + 1; i <= right; i++) {
			if (arr[i] < arr[i - 1]) {
				z = i;
			}
		}
		vector<int> ans;
		if (left) {
			ans.pb(left);
		}
		ans.pb(z - left);
		ans.pb(right - z + 1);
		if (right != (n - 1)) {
			ans.pb(n - right - 1);
		}
		update(ans);
		return ans;
	};
	
	vector<vector<int>> res;
	for (int i = 0; i < n; i++) {
		bool sorted = true;
		int x, y;
		for (int i = 0; i < n; i++) {
			bool found = false;
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == (arr[j] + 1)) {
					found = true;
					x = i, y = j;
					break;
				}
			}
			if (found) {
				res.pb(change(x, y));
				sorted = false;
				break;
			}
		}
		if (sorted) break;
	}
	cout << size(res) << endl;
	for (auto r : res) {
		cout << size(r) << " ";
		for (auto x : r) {
			cout << x << " ";
		} cout << endl;
	}
	return 0;
}