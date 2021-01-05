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

vector<int> getRes(vector<array<int, 3>> arr, vector<int> tmp, vector<array<int, 3>> brr, vector<int> mmp, int n) {
	sort(_all(arr));
	sort(_all(brr));
	vector<int> mxs(n);
	mxs[0] = arr[0][2];
	for (int i = 1; i < n; i++) {
		if (tmp[mxs[i - 1]] > arr[i][1]) {
			mxs[i] = arr[i][2];
		} else {
			mxs[i] = mxs[i - 1];
		}
	}
	vector<int> res(n, -1);
	for (auto a : arr) {
		array<int, 3> xx = { a[0], -INF, -INF };
		int loc = upper_bound(_all(arr), xx) - arr.begin() - 1;
		if (loc != -1) {
			if (tmp[mxs[loc]] < a[1]) {
				res[a[2]] = mxs[loc] + 1;
			}
		}
	}
	mxs.resize(n);
	mxs[0] = brr[0][2];
	for (int i = 1; i < n; i++) {
		if (mmp[mxs[i - 1]] > brr[i][1]) {
			mxs[i] = brr[i][2];
		} else {
			mxs[i] = mxs[i - 1];
		}
	}
	for (auto a : brr) {
		array<int, 3> xx = { a[1], -INF, -INF };
		int loc = upper_bound(_all(brr), xx) - brr.begin() - 1;
		if (loc != -1) {
			if (mmp[mxs[loc]] < a[0]) {
				res[a[2]] = mxs[loc] + 1;
			}
		}
	}
	return res;
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<array<int, 3>> arr(n), brr(n);
		vector<int> tmp(n), mmp(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1];
			arr[i][2] = i;
			brr[i] = { arr[i][1], arr[i][0], arr[i][2] };
			mmp[i] = brr[i][1];
			tmp[i] = arr[i][1];
		}
		vector<int> r1 = getRes(arr, tmp, brr, mmp, n);
		for (int i = 0; i < n; i++) {
			cout << r1[i] << " ";
		} cout << endl;
	}
	return 0;
}