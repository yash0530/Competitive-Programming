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

int mxBit(int a) {
	int ans = 0;
	while (a) {
		ans = a;
		a = (a & (a - 1));
	}
	return ans;
}

signed main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	set<pii> ans;
	for (int i = 0; i < (n - 2); i++) {
		int sum = 0;
		int mxbit = mxBit(arr[i]);
		for (int j = i + 1; j < (n - 1); j++) {
			sum += arr[j];
			if (sum >= (2 * mxbit)) break;
			if ((arr[i] ^ arr[j + 1]) == sum) {
				ans.insert({ i, j + 1 });
			}
		}
	}
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < (n - 2); i++) {
		int sum = 0;
		int mxbit = mxBit(arr[i]);
		for (int j = i + 1; j < (n - 1); j++) {
			sum += arr[j];
			if (sum >= (2 * mxbit)) break;
			if ((arr[i] ^ arr[j + 1]) == sum) {
				ans.insert({ n - j - 2, n - i - 1 });
			}
		}
	}
	cout << size(ans) << endl;
	return 0;
}